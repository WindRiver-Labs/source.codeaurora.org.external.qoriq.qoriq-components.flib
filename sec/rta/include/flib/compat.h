/* Copyright 2013 Freescale Semiconductor, Inc. */

#ifndef __RTA_COMPAT_H__
#define __RTA_COMPAT_H__

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#ifdef __GLIBC__
#include <byteswap.h>
/* FSL's Embedded Warrior C Library; assume AIOP or MC environment */
#elif defined(__EWL__) && (defined(AIOP) || defined(MC))
#include "fsl_endian.h"
#else
#error Environment not supported!
#endif

#ifndef __always_inline
#define __always_inline inline __attribute__((always_inline))
#endif

#ifndef pr_debug
#ifdef RTA_DEBUG
#define pr_debug(fmt, ...)    printf(fmt, ##__VA_ARGS__)
#else
#define pr_debug(fmt, ...)
#endif
#endif

/**
 * ARRAY_SIZE(x) - Returns the number of elements in an array
 */
#ifndef ARRAY_SIZE
#define ARRAY_SIZE(x) (sizeof(x) / sizeof((x)[0]))
#endif

#ifndef ALIGN
#define ALIGN(x, a) (((x) + ((typeof(x))(a) - 1)) & ~((typeof(x))(a) - 1))
#endif

/* Use Linux naming convention */
#ifdef __GLIBC__
#define swab16(x) bswap_16(x)
#define swab32(x) bswap_32(x)
#define swab64(x) bswap_64(x)
#elif defined(__EWL__) && (defined(AIOP) || defined(MC))
#define swab16(x) swap_uint16(x)
#define swab32(x) swap_uint32(x)
#define swab64(x) swap_uint64(x)
#endif

#endif /* __RTA_COMPAT_H__ */
