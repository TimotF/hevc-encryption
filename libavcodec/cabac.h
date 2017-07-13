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
 * Context Adaptive Binary Arithmetic Coder.
 */

#ifndef AVCODEC_CABAC_H
#define AVCODEC_CABAC_H

#include <stdint.h>

#include "put_bits.h"

extern const uint8_t ff_h264_cabac_tables[512 + 4*2*64 + 4*64 + 63];
#define H264_NORM_SHIFT_OFFSET 0
#define H264_LPS_RANGE_OFFSET 512
#define H264_MLPS_STATE_OFFSET 1024
#define H264_LAST_COEFF_FLAG_OFFSET_8x8_OFFSET 1280

#define CABAC_BITS 16
#define CABAC_MASK ((1<<CABAC_BITS)-1)

typedef struct CABACContext{
    int low;
    int range;
    int outstanding_count;
    const uint8_t *bytestream_start;
    uint8_t *bytestream;
    const uint8_t *bytestream_end;
    PutBitContext pb;
}CABACContext;

typedef struct
{
    uint8_t uc_state;
} cabac_ctx_t;

typedef struct
{
    cabac_ctx_t *cur_ctx;
    uint32_t low;
    uint32_t range;
    uint32_t buffered_byte;
    int32_t num_buffered_bytes;
    int32_t bits_left;
    int8_t only_count;
    PutBitContext pb;

    // CONTEXTS
    struct
    {
        cabac_ctx_t sao_merge_flag_model;
        cabac_ctx_t sao_type_idx_model;
        cabac_ctx_t split_flag_model[3]; //!< \brief split flag context models
        cabac_ctx_t intra_mode_model;    //!< \brief intra mode context models
        cabac_ctx_t chroma_pred_model[2];
        cabac_ctx_t inter_dir[5];
        cabac_ctx_t trans_subdiv_model[3]; //!< \brief intra mode context models
        cabac_ctx_t qt_cbf_model_luma[4];
        cabac_ctx_t qt_cbf_model_chroma[4];
        cabac_ctx_t cu_qp_delta_abs[4];
        cabac_ctx_t part_size_model[4];
        cabac_ctx_t cu_sig_coeff_group_model[4];
        cabac_ctx_t cu_sig_model_luma[27];
        cabac_ctx_t cu_sig_model_chroma[15];
        cabac_ctx_t cu_ctx_last_y_luma[15];
        cabac_ctx_t cu_ctx_last_y_chroma[15];
        cabac_ctx_t cu_ctx_last_x_luma[15];
        cabac_ctx_t cu_ctx_last_x_chroma[15];
        cabac_ctx_t cu_one_model_luma[16];
        cabac_ctx_t cu_one_model_chroma[8];
        cabac_ctx_t cu_abs_model_luma[4];
        cabac_ctx_t cu_abs_model_chroma[2];
        cabac_ctx_t cu_pred_mode_model;
        cabac_ctx_t cu_skip_flag_model[3];
        cabac_ctx_t cu_merge_idx_ext_model;
        cabac_ctx_t cu_merge_flag_ext_model;
        cabac_ctx_t cu_transquant_bypass;
        cabac_ctx_t cu_mvd_model[2];
        cabac_ctx_t cu_ref_pic_model[2];
        cabac_ctx_t mvp_idx_model[2];
        cabac_ctx_t cu_qt_root_cbf_model;
        cabac_ctx_t transform_skip_model_luma;
        cabac_ctx_t transform_skip_model_chroma;
    } ctx;
} cabac_data_t;

void ff_init_cabac_encoder(CABACContext *c, uint8_t *buf, int buf_size);
int ff_init_cabac_decoder(CABACContext *c, const uint8_t *buf, int buf_size);
void ff_init_cabac_states(void);

#endif /* AVCODEC_CABAC_H */
