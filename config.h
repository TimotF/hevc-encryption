/* Automatically generated by configure - do not modify! */
#ifndef FFMPEG_CONFIG_H
#define FFMPEG_CONFIG_H
#define TRUE  1
#define FALSE 0
#define ON    1
#define OFF   0
#define FFMPEG_CONFIGURATION ""
#define FFMPEG_LICENSE "LGPL version 2.1 or later"
#define CONFIG_THIS_YEAR 2016
#define FFMPEG_DATADIR "/usr/local/share/ffmpeg"
#define AVCONV_DATADIR "/usr/local/share/ffmpeg"
#define CC_IDENT "gcc 5.2.1 (Ubuntu 5.2.1-22ubuntu2) 20151010"
#define av_restrict
#if defined(WIN32)
#define EXTERN_ASM 
#else
#define EXTERN_ASM _
#endif
#define BUILDSUF ""
#define SLIBSUF ".dylib"
#ifdef __APPLE_CC__
#define EXTERN_PREFIX "_"
#else
    #ifdef __MINGW32__
        #ifdef __MINGW64__
        #define EXTERN_PREFIX ""
        #else
        #define EXTERN_PREFIX "_"
        #endif
    #else
        #define EXTERN_PREFIX ""
    #endif
#endif

#define GCC_VERSION (__GNUC__ * 10000 \
                               + __GNUC_MINOR__ * 100 \
                               + __GNUC_PATCHLEVEL__)
#define MIN_GCC_VERSION_MC 40405
#define HAVE_MMX2 HAVE_MMXEXT
#define SWS_MAX_FILTER_SIZE 256
#define ARCH_AARCH64 0
#define ARCH_ALPHA 0
#define ARCH_ARM 0
#define ARCH_AVR32 0
#define ARCH_AVR32_AP 0
#define ARCH_AVR32_UC 0
#define ARCH_BFIN 0
#define ARCH_IA64 0
#define ARCH_M68K 0
#define ARCH_MIPS 0
#define ARCH_MIPS64 0
#define ARCH_PARISC 0
#define ARCH_PPC 0
#define ARCH_PPC64 0
#define ARCH_S390 0
#define ARCH_SH4 0
#define ARCH_SPARC 0
#define ARCH_SPARC64 0
#define ARCH_TILEGX 0
#define ARCH_TILEPRO 0
#define ARCH_TOMI 0
#define ARCH_X86 1
#ifdef X86_32
#define ARCH_X86_32 1
#define ARCH_X86_64 0
#else
#define ARCH_X86_32 0
#define ARCH_X86_64 1
#endif
#define HAVE_ARMV5TE 0
#define HAVE_ARMV6 0
#define HAVE_ARMV6T2 0
#define HAVE_NEON 0
#define HAVE_VFP 0
#define HAVE_VFPV3 0
#define HAVE_ALTIVEC 0
#define HAVE_AVX     TRUE
#define HAVE_AVX2    FALSE
#define HAVE_MMX     ARCH_X86
#define HAVE_MMXEXT  ARCH_X86_64
#define HAVE_SSE     ARCH_X86_64
#define HAVE_SSE2    TRUE
#define HAVE_SSE3    TRUE
#define HAVE_SSE4    TRUE
#define HAVE_SSE42   TRUE
#define HAVE_SSSE3   TRUE
#define HAVE_CPUNOP 1
#define HAVE_I686 1
#define HAVE_MIPSFPU 0
#define HAVE_ARMV5TE_EXTERNAL 0
#define HAVE_ARMV6_EXTERNAL 0
#define HAVE_ARMV6T2_EXTERNAL 0
#define HAVE_NEON_EXTERNAL 0
#define HAVE_VFP_EXTERNAL 0
#define HAVE_VFPV3_EXTERNAL 0
#define HAVE_ALTIVEC_EXTERNAL 0
#define HAVE_AMD3DNOW_EXTERNAL 1
#define HAVE_AVX_EXTERNAL    TRUE
#define HAVE_AVX2_EXTERNAL   FALSE
#define HAVE_MMX_EXTERNAL    ARCH_X86
#define HAVE_MMXEXT_EXTERNAL ARCH_X86_64
#define HAVE_SSE_EXTERNAL    ARCH_X86_64
#define HAVE_SSE2_EXTERNAL   TRUE
#define HAVE_SSE3_EXTERNAL   TRUE
#define HAVE_SSE4_EXTERNAL   TRUE
#define HAVE_SSE42_EXTERNAL  TRUE
#define HAVE_SSSE3_EXTERNAL  TRUE
#define HAVE_CPUNOP_EXTERNAL 0
#define HAVE_I686_EXTERNAL 0
#define HAVE_MIPSFPU_EXTERNAL 0
#define HAVE_ARMV5TE_INLINE 0
#define HAVE_ARMV6_INLINE 0
#define HAVE_ARMV6T2_INLINE 0
#define HAVE_NEON_INLINE 0
#define HAVE_VFP_INLINE 0
#define HAVE_VFPV3_INLINE 0
#define HAVE_ALTIVEC_INLINE 0
#define HAVE_AVX_INLINE    TRUE
#define HAVE_AVX2_INLINE   FALSE
#if defined(WIN32)
#define HAVE_MMX_INLINE 0
#define HAVE_MMXEXT_INLINE 0
#define HAVE_SSE_INLINE 0
#define HAVE_SSE2_INLINE    0
#define HAVE_SSE3_INLINE    0
#define HAVE_SSE4_INLINE    0
#define HAVE_SSE42_INLINE   0
#define HAVE_SSSE3_INLINE   0
#else
#define HAVE_MMX_INLINE     ARCH_X86
#define HAVE_MMXEXT_INLINE  ARCH_X86_64
#define HAVE_SSE_INLINE     ARCH_X86_64
#define HAVE_SSE2_INLINE    TRUE
#define HAVE_SSE3_INLINE    TRUE
#define HAVE_SSE4_INLINE    TRUE
#define HAVE_SSE42_INLINE   TRUE
#define HAVE_SSSE3_INLINE   TRUE
#endif
#define HAVE_CPUNOP_INLINE 0
#define HAVE_I686_INLINE 0
#define HAVE_MIPSFPU_INLINE 0
#define HAVE_YASM         ON
#define HAVE_PTHREADS       1
#if defined(WIN32)
#if HAVE_PTHREADS
#define HAVE_W32THREADS 0
#else
#define HAVE_W32THREADS 1
#endif
#define HAVE_OS2THREADS 0
#define HAVE_ATOMICS_GCC 0
#define HAVE_ATOMICS_SUNCC 0
#define HAVE_ATOMICS_WIN32 1
#else
#define HAVE_W32THREADS 0
#define HAVE_OS2THREADS 0
#endif
#define HAVE_ATOMICS_GCC 1
#define HAVE_ATOMICS_SUNCC 0
#define HAVE_ATOMICS_WIN32 0
#define HAVE_ALIGNED_STACK 1
#define HAVE_FAST_64BIT 1
#define HAVE_FAST_CLZ 1
#define HAVE_FAST_CMOV 1
#define HAVE_LOCAL_ALIGNED_8 1
#define HAVE_LOCAL_ALIGNED_16 1
#define HAVE_LOCAL_ALIGNED_32 1
#define HAVE_SIMD_ALIGN_16 1
#define HAVE_ATOMIC_COMPARE_EXCHANGE 1
#if defined(WIN32)
#define HAVE_MM_EMPTY 0
#else
#define HAVE_MM_EMPTY 1
#endif

#define HAVE_RDTSC 0
#define HAVE_SYNC_VAL_COMPARE_AND_SWAP 1
#if defined(WIN32)
#define HAVE_INLINE_ASM 0
#else
#define HAVE_INLINE_ASM   ARCH_X86
#endif
#define HAVE_BIGENDIAN 0
#define HAVE_FAST_UNALIGNED 1
#define HAVE_ALTIVEC_H 0
#define HAVE_ARPA_INET_H 1
#define HAVE_DIRECT_H 0
#define HAVE_DIRENT_H 1
#define HAVE_IO_H 0
#define HAVE_MACH_MACH_TIME_H 0
#ifdef __APPLE_CC__
#define HAVE_MALLOC_H 0
#else
#define HAVE_MALLOC_H 1
#endif
#define HAVE_POLL_H 1
#define HAVE_SYS_PARAM_H 1
#define HAVE_SYS_SELECT_H 1
#define HAVE_SYS_TIME_H 1
#define HAVE_UDPLITE_H 0
#define HAVE_UNISTD_H 1
#define HAVE_VALGRIND_VALGRIND_H 0
#define HAVE_WINDOWS_H 0
#define HAVE_WINSOCK2_H 0
#define HAVE_ATANF 1
#define HAVE_ATAN2F 1
#define HAVE_CBRT 1
#define HAVE_CBRTF 1
#define HAVE_CBRTF 1
#define HAVE_COPYSIGN 1
#define HAVE_COSF 1
#define HAVE_ERF 1
#define HAVE_EXP2 1
#define HAVE_EXP2F 1
#define HAVE_EXP2F 1
#define HAVE_EXPF 1
#define HAVE_HYPOT 1
#define HAVE_ISFINITE 1
#define HAVE_ISINF 1
#define HAVE_ISNAN 1
#define HAVE_LDEXPF 1
#define HAVE_LLRINT 1
#define HAVE_LLRINTF 1
#define HAVE_LLRINTF 1
#define HAVE_LOG2 1
#define HAVE_LOG2F 1
#define HAVE_LOG2F 1
#define HAVE_LOG10F 1
#define HAVE_LRINT 1
#define HAVE_LRINTF 1
#define HAVE_LRINTF 1
#define HAVE_POWF 1
#define HAVE_RINT 1
#define HAVE_ROUND 1
#define HAVE_ROUNDF 1
#define HAVE_ROUNDF 1
#define HAVE_SINF 1
#define HAVE_TRUNC 1
#define HAVE_TRUNCF 1
#define HAVE_TRUNCF 1
#define HAVE_ACCESS 1
#define HAVE_ALIGNED_MALLOC 0
#define HAVE_ARC4RANDOM 0
#define HAVE_CLOCK_GETTIME 1
#define HAVE_CLOSESOCKET 0
#define HAVE_CRYPTGENRANDOM 0
#define HAVE_FCNTL 1
#define HAVE_GETADDRINFO 1
#define HAVE_GETHRTIME 0
#define HAVE_GETPROCESSAFFINITYMASK 0
#define HAVE_GETSYSTEMTIMEASFILETIME 0
#define HAVE_GETTIMEOFDAY 1
#define HAVE_GMTIME_R 1
#define HAVE_INET_ATON 1
#define HAVE_ISATTY 1
#define HAVE_LOCALTIME_R 1
#define HAVE_LSTAT 1
#define HAVE_MACH_ABSOLUTE_TIME 0
#define HAVE_MAPVIEWOFFILE 0
#define HAVE_MEMALIGN 1
#define HAVE_MKSTEMP 1
#define HAVE_MMAP 1
#define HAVE_NANOSLEEP 1
#define HAVE_POSIX_MEMALIGN 1
#define HAVE_PTHREAD_CANCEL 1
#define HAVE_SCHED_GETAFFINITY 1
#define HAVE_SETCONSOLETEXTATTRIBUTE 0
#define HAVE_SETMODE 0
#define HAVE_SLEEP 0
#define HAVE_STRERROR_R 1
#define HAVE_SYSCONF 1
#define HAVE_SYSCTL 1
#define HAVE_USLEEP 1
#define HAVE_AS_FUNC 0
#define HAVE_AS_OBJECT_ARCH 0
#define HAVE_ASM_MOD_Q 0
#define HAVE_EBP_AVAILABLE ARCH_X86_64
#define HAVE_INLINE_ASM_DIRECT_SYMBOL_REFS 1
#define HAVE_INLINE_ASM_DIRECT_SYMBOL_REFS 1
#define HAVE_INLINE_ASM_LABELS 1
#define HAVE_INLINE_ASM_NONLOCAL_LABELS 1
#define HAVE_PRAGMA_DEPRECATED 1
#define HAVE_SYMVER_ASM_LABEL 0
#define HAVE_SYMVER_GNU_ASM 1
#define HAVE_VFP_ARGS 0
#define HAVE_VFP_ARGS 0
#define HAVE_XMM_CLOBBERS 1
#define HAVE_CONDITION_VARIABLE_PTR 0
#define HAVE_SOCKLEN_T 1
#define HAVE_STRUCT_ADDRINFO 1
#define HAVE_STRUCT_GROUP_SOURCE_REQ 1
#define HAVE_STRUCT_IP_MREQ_SOURCE 1
#define HAVE_STRUCT_IPV6_MREQ 1
#define HAVE_STRUCT_POLLFD 1
#define HAVE_STRUCT_SOCKADDR_IN6 1
#define HAVE_STRUCT_SOCKADDR_SA_LEN 0
#define HAVE_STRUCT_SOCKADDR_STORAGE 1
#define HAVE_ATOMICS_NATIVE 1
#define HAVE_DOS_PATHS 0
#define HAVE_LIBC_MSVCRT 0
#define HAVE_SECTION_DATA_REL_RO 1
#define HAVE_THREADS 1
#define HAVE_WINRT 0
#define CONFIG_BZLIB 0
#define CONFIG_ICONV 0
#define CONFIG_ZLIB 0
#define CONFIG_ZLIB_DECODER 0
#define CONFIG_ZLIB_ENCODER 0
#define CONFIG_FTRAPV 0
#define CONFIG_GRAY 0
#define CONFIG_HARDCODED_TABLES 0
#define CONFIG_SAFE_BITSTREAM_READER 1
#define CONFIG_SHARED 0
#define CONFIG_SMALL 0
#define CONFIG_DCT 0
#define CONFIG_ERROR_RESILIENCE 0
#define CONFIG_LZO 0
#define CONFIG_MDCT 0
#define CONFIG_NETWORK 0
#define CONFIG_RDFT 0
#define CONFIG_MEMALIGN_HACK 0
#define CONFIG_MEMORY_POISONING 0
#define CONFIG_PIC 0
#define CONFIG_THUMB 0
#define CONFIG_VALGRIND_BACKTRACE 0
#define CONFIG_DIRAC_PARSE 0
#define CONFIG_FAANDCT 0
#define CONFIG_FAANIDCT 0
#define CONFIG_FRAME_THREAD_ENCODER 0
#define CONFIG_ME_CMP 0
#define CONFIG_MPEGVIDEO 0
#define CONFIG_DIRAC_DECODER 0
#define CONFIG_H261_DECODER 0
#define CONFIG_H263_DECODER 0
#define CONFIG_H264_DECODER 1
#define CONFIG_H264_VDPAU_DECODER 0
#define CONFIG_HEVC_DECODER 1
#define CONFIG_MPEG4_DECODER 0
#define CONFIG_VP3_DECODER 0
#define CONFIG_DATA_DEMUXER 0
#define CONFIG_DV_DEMUXER 0
#define CONFIG_LOAS_DEMUXER 0
#define CONFIG_MJPEG_DEMUXER 0
#define CONFIG_MPEGVIDEO_DEMUXER 0
#define CONFIG_MOV_DEMUXER 1
#define CONFIG_MPEGTS_DEMUXER 1
#define CONFIG_SNOW_ENCODER 0
#define CONFIG_H264_D3D11VA_HWACCEL 0
#define CONFIG_H264_DXVA2_HWACCEL 0
#define CONFIG_H264_VAAPI_HWACCEL 0
#define CONFIG_H264_VDA_HWACCEL 0
#define CONFIG_H264_VDPAU_HWACCEL 0
#define CONFIG_H264_VIDEOTOOLBOX_HWACCEL 0
#define CONFIG_IMAGE2_MUXER 0
#define CONFIG_VORBIS_PARSER 0
#define CONFIG_HARDCODED_TABLES 0
#define CONFIG_H264CHROMA 1
#define CONFIG_H264DSP 1
#define CONFIG_H264PRED 1
#define CONFIG_H264QPEL 1
#define CONFIG_HPELDSP 0
#define CONFIG_H261_DECODER 0
#define CONFIG_H263_DECODER 0
#define CONFIG_H264_DECODER 1
#define CONFIG_H264_VDPAU_DECODER 0
#define CONFIG_HEVC_DECODER 1
#define CONFIG_SHVC_DECODER 1
#define CONFIG_H264_DEMUXER 1
#define CONFIG_HEVC_DEMUXER 1
#define CONFIG_SHVC_DEMUXER 1
#define CONFIG_H264_CUVID_HWACCEL 0
#define CONFIG_H264_D3D11VA_HWACCEL 0
#define CONFIG_H264_DXVA2_HWACCEL 0
#define CONFIG_H264_QSV_HWACCEL 0
#define CONFIG_H264_VAAPI_HWACCEL 0
#define CONFIG_H264_VDA_HWACCEL 0
#define CONFIG_H264_VDA_OLD_HWACCEL 0
#define CONFIG_H264_VDPAU_HWACCEL 0
#define CONFIG_H264_VIDEOTOOLBOX_HWACCEL 0
#define CONFIG_H264_PARSER 1
#define CONFIG_HEVC_PARSER 1
#define CONFIG_SHVC_PARSER 1
#define CONFIG_FILE_PROTOCOL 1
#define CONFIG_PIPE_PROTOCOL 0
#endif /* FFMPEG_CONFIG_H */
#define HEVC_ENCRYPTION 1
#define COM16_C806_EMT 0 
