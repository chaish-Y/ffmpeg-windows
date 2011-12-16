/*
 * Copyright (c) 2000, 2001, 2002 Fabrice Bellard
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
//****************************************************************************//
//libavutil\cpu.h
//	定义不同CPU的相关信息
//学习的地方：
//1.不同的CPU指令是如何在具体的运算中起到特别的作用的？
//2.之前有介绍ffmpeg将无论是PC的Intel， AMD的CPU还是ARM7， ARM9的CPU
//都是当作一个泛型的DSP来看待，但是这里没有感觉的这种设计
//这是一个疑问，需要以后弄明白
//附录：
//
//****************************************************************************//

#ifndef AVUTIL_CPU_H
#define AVUTIL_CPU_H
#include "libavutil/attributes.h"

#define AV_CPU_FLAG_FORCE    0x80000000 /* force usage of selected flags (OR) */

/* lower 16 bits - CPU features */
#define AV_CPU_FLAG_MMX          0x0001 ///< standard MMX
#define AV_CPU_FLAG_MMX2         0x0002 ///< SSE integer functions or AMD MMX ext
#define AV_CPU_FLAG_3DNOW        0x0004 ///< AMD 3DNOW
#define AV_CPU_FLAG_SSE          0x0008 ///< SSE functions
#define AV_CPU_FLAG_SSE2         0x0010 ///< PIV SSE2 functions
#define AV_CPU_FLAG_SSE2SLOW 0x40000000 ///< SSE2 supported, but usually not faster
#define AV_CPU_FLAG_3DNOWEXT     0x0020 ///< AMD 3DNowExt
#define AV_CPU_FLAG_SSE3         0x0040 ///< Prescott SSE3 functions
#define AV_CPU_FLAG_SSE3SLOW 0x20000000 ///< SSE3 supported, but usually not faster
#define AV_CPU_FLAG_SSSE3        0x0080 ///< Conroe SSSE3 functions
#define AV_CPU_FLAG_ATOM     0x10000000 ///< Atom processor, some SSSE3 instructions are slower
#define AV_CPU_FLAG_SSE4         0x0100 ///< Penryn SSE4.1 functions
#define AV_CPU_FLAG_SSE42        0x0200 ///< Nehalem SSE4.2 functions
#define AV_CPU_FLAG_AVX          0x4000 ///< AVX functions: requires OS support even if YMM registers aren't used
#define AV_CPU_FLAG_IWMMXT       0x0100 ///< XScale IWMMXT
#define AV_CPU_FLAG_ALTIVEC      0x0001 ///< standard

/**
 * Return the flags which specify extensions supported by the CPU.
 */
FFMPEGLIB_API int av_get_cpu_flags(void);

/* The following CPU-specific functions shall not be called directly. */
FFMPEGLIB_API int ff_get_cpu_flags_arm(void);
FFMPEGLIB_API int ff_get_cpu_flags_ppc(void);
FFMPEGLIB_API int ff_get_cpu_flags_x86(void);

#endif  /* AVUTIL_CPU_H */
