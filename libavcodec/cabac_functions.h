/*
 * H.26L/H.264/AVC/JVT/14496-10/... encoder/decoder
 * Copyright (c) 2003 Michael Niedermayer <michaelni@gmx.at>
 *
 * This file is part of FFmpeg.
 *
 * FFmpeg is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * FFmpeg is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with FFmpeg; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

/**
 * @file
 * Context Adaptive Binary Arithmetic Coder inline functions
 */

#ifndef AVCODEC_CABAC_FUNCTIONS_H
#define AVCODEC_CABAC_FUNCTIONS_H

#include <stdint.h>

#include "hevc.h"
#include "cabac.h"
#include "config.h"

#ifndef UNCHECKED_BITSTREAM_READER
#define UNCHECKED_BITSTREAM_READER !CONFIG_SAFE_BITSTREAM_READER
#endif

#if ARCH_AARCH64
#   include "aarch64/cabac.h"
#endif
#if ARCH_ARM
#   include "arm/cabac.h"
#endif
#if ARCH_X86
#   include "x86/cabac.h"
#endif

static const uint8_t * const ff_h264_norm_shift = ff_h264_cabac_tables + H264_NORM_SHIFT_OFFSET;
static const uint8_t * const ff_h264_lps_range = ff_h264_cabac_tables + H264_LPS_RANGE_OFFSET;
static const uint8_t * const ff_h264_mlps_state = ff_h264_cabac_tables + H264_MLPS_STATE_OFFSET;
static const uint8_t * const ff_h264_last_coeff_flag_offset_8x8 = ff_h264_cabac_tables + H264_LAST_COEFF_FLAG_OFFSET_8x8_OFFSET;

#if !defined(get_cabac_bypass) || !defined(get_cabac_terminate)
static void refill(CABACContext *c){
#if CABAC_BITS == 16
        c->low+= (c->bytestream[0]<<9) + (c->bytestream[1]<<1);
#else
        c->low+= c->bytestream[0]<<1;
#endif
    c->low -= CABAC_MASK;
#if !UNCHECKED_BITSTREAM_READER
    if (c->bytestream < c->bytestream_end)
#endif
        c->bytestream += CABAC_BITS / 8;
}
#endif

#ifndef get_cabac_terminate
static inline void renorm_cabac_decoder_once(CABACContext *c){
    int shift= (uint32_t)(c->range - 0x100)>>31;
    c->range<<= shift;
    c->low  <<= shift;
    if(!(c->low & CABAC_MASK))
        refill(c);
}
#endif

#ifndef get_cabac_inline
static void refill2(CABACContext *c){
    int i;
    unsigned x;
#if !HAVE_FAST_CLZ
    x= c->low ^ (c->low-1);
    i= 7 - ff_h264_norm_shift[x>>(CABAC_BITS-1)];
#else
    i = ff_ctz(c->low) - CABAC_BITS;
#endif

    x= -CABAC_MASK;

#if CABAC_BITS == 16
        x+= (c->bytestream[0]<<9) + (c->bytestream[1]<<1);
#else
        x+= c->bytestream[0]<<1;
#endif

    c->low += x<<i;
#if !UNCHECKED_BITSTREAM_READER
    if (c->bytestream < c->bytestream_end)
#endif
        c->bytestream += CABAC_BITS/8;
}
#endif

#ifndef get_cabac_inline
static av_always_inline int get_cabac_inline(CABACContext *c, uint8_t * const state){
    int s = *state;
    int RangeLPS= ff_h264_lps_range[2*(c->range&0xC0) + s];
    int bit, lps_mask;

    c->range -= RangeLPS;
    lps_mask= ((c->range<<(CABAC_BITS+1)) - c->low)>>31;

    c->low -= (c->range<<(CABAC_BITS+1)) & lps_mask;
    c->range += (RangeLPS - c->range) & lps_mask;

    s^=lps_mask;
    *state= (ff_h264_mlps_state+128)[s];
    bit= s&1;

    lps_mask= ff_h264_norm_shift[c->range];
    c->range<<= lps_mask;
    c->low  <<= lps_mask;
    if(!(c->low & CABAC_MASK))
        refill2(c);
    return bit;
}
#endif

static int av_noinline av_unused get_cabac_noinline(CABACContext *c, uint8_t * const state){
    return get_cabac_inline(c,state);
}

static int av_unused get_cabac(CABACContext *c, uint8_t * const state){
    return get_cabac_inline(c,state);
}

#ifndef get_cabac_bypass
static int av_unused get_cabac_bypass(CABACContext *c){
    int range;
    c->low += c->low;

    if(!(c->low & CABAC_MASK))
        refill(c);

    range= c->range<<(CABAC_BITS+1);
    if(c->low < range){
        return 0;
    }else{
        c->low -= range;
        return 1;
    }
}
#endif

#ifndef get_cabac_bypass_sign
static av_always_inline int get_cabac_bypass_sign(CABACContext *c, int val){
    int range, mask;
    c->low += c->low;

    if(!(c->low & CABAC_MASK))
        refill(c);

    range= c->range<<(CABAC_BITS+1);
    c->low -= range;
    mask= c->low >> 31;
    range &= mask;
    c->low += range;
    return (val^mask)-mask;
}
#endif

/**
 * @return the number of bytes read or 0 if no end
 */
#ifndef get_cabac_terminate
static int av_unused get_cabac_terminate(CABACContext *c){
    c->range -= 2;
    if(c->low < c->range<<(CABAC_BITS+1)){
        renorm_cabac_decoder_once(c);
        return 0;
    }else{
        return c->bytestream - c->bytestream_start;
    }
}
#endif

/**
 * Skip @p n bytes and reset the decoder.
 * @return the address of the first skipped byte or NULL if there's less than @p n bytes left
 */
#ifndef skip_bytes
static av_unused const uint8_t* skip_bytes(CABACContext *c, int n) {
    const uint8_t *ptr = c->bytestream;

    if (c->low & 0x1)
        ptr--;
#if CABAC_BITS == 16
    if (c->low & 0x1FF)
        ptr--;
#endif
    if ((int) (c->bytestream_end - ptr) < n)
        return NULL;
    if (ff_init_cabac_decoder(c, ptr + n, c->bytestream_end - ptr - n) < 0)
        return NULL;

    return ptr;
}
#endif




// Globals
extern const uint8_t kvz_g_auc_next_state_mps[128];
extern const uint8_t kvz_g_auc_next_state_lps[128];
extern const uint8_t kvz_g_auc_lpst_table[64][4];
extern const uint8_t kvz_g_auc_renorm_table[32];


// Encoder functions
void oh_cabac_start(HEVCContext *s);
void oh_cabac_encode_bin(HEVCContext *s, uint32_t bin_value);
void oh_cabac_encode_bin_ep(HEVCContext *s, uint32_t bin_value);
void oh_cabac_encode_bins_ep(HEVCContext *s, uint32_t bin_values, int num_bins);
void oh_cabac_encode_bin_trm(HEVCContext *s, uint8_t bin_value);
void oh_cabac_write(HEVCContext *s);
void oh_cabac_finish(HEVCContext *s);
void oh_cabac_write_coeff_remain(HEVCContext *s, uint32_t symbol,
                              uint32_t r_param);
void oh_cabac_write_coeff_remain_encry(HEVCContext *s, const uint32_t symbol,
		const uint32_t r_param, int32_t base_level);
void oh_cabac_write_ep_ex_golomb( HEVCContext *s,uint32_t symbol, uint32_t count);
void oh_cabac_write_unary_max_symbol(HEVCContext *s, uint32_t symbol, int32_t offset,
                                  uint32_t max_symbol);
void oh_cabac_write_unary_max_symbol_ep(HEVCContext *s, unsigned int symbol, unsigned int max_symbol);


// Macros
#define CTX_STATE(ctx) ((ctx)->uc_state >> 1)
#define CTX_MPS(ctx) ((ctx)->uc_state & 1)
#define CTX_UPDATE_LPS(ctx) { (ctx)->uc_state = kvz_g_auc_next_state_lps[ (ctx)->uc_state ]; }
#define CTX_UPDATE_MPS(ctx) { (ctx)->uc_state = kvz_g_auc_next_state_mps[ (ctx)->uc_state ]; }

#ifdef VERBOSE
  #define CABAC_BIN(data, value, name) { \
    uint32_t prev_state = (data)->ctx->uc_state; \
    oh_cabac_encode_bin((data), (value)) \
    printf("%s = %u, state = %u -> %u\n", \
           (name), (uint32_t)(value), prev_state, (data)->ctx->uc_state); }

  #define CABAC_BINS_EP(data, value, bins, name) { \
    uint32_t prev_state = (data)->ctx->uc_state; \
    oh_cabac_encode_bins_ep((data), (value), (bins)); \
    printf("%s = %u(%u bins), state = %u -> %u\n", \
           (name), (uint32_t)(value), (bins), prev_state, (data)->ctx->uc_state); }

  #define CABAC_BIN_EP(data, value, name) { \
    uint32_t prev_state = (data)->ctx->uc_state; \
    oh_cabac_encode_bin_ep((data), (value)); \
    printf("%s = %u, state = %u -> %u\n", \
           (name), (uint32_t)(value), prev_state, (data)->ctx->uc_state); }
#else
  #define CABAC_BIN(data, value, name) \
    oh_cabac_encode_bin((data), (value));
  #define CABAC_BINS_EP(data, value, bins, name) \
    oh_cabac_encode_bins_ep((data), (value), (bins));
  #define CABAC_BIN_EP(data, value, name) \
    oh_cabac_encode_bin_ep((data), (value));
#endif




#endif /* AVCODEC_CABAC_FUNCTIONS_H */
