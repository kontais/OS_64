#ifndef __STDINT_H__
#define __STDINT_H__

/*
 * Определения типов данных
 */

typedef unsigned char  uint8_t;
typedef signed   char  int8_t;
typedef unsigned short uint16_t;
typedef signed   short int16_t;
typedef unsigned int   uint32_t;
typedef signed   int   int32_t;
typedef unsigned long  uint64_t;
typedef signed   long  int64_t;
typedef uint64_t size_t;
typedef int64_t  ssize_t;
typedef int64_t  off_t;

#define NULL ((void *)0)

#endif // __STDINT_H__
