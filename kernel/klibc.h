#ifndef __KLIBC_H__
#define __KLIBC_H__

#include <stdint.h>

void printf(const char *fmt, ...);

void getsn(void);

char getc();

void ungetc(char c);

char *strncpy(char *dest, char *src, int len);

void *memset(void *mem, int c, uint32_t n);

void *zeromem(void *mem, uint32_t n);

void *memcpy(void *dest, const void *src, uint32_t n);

// Для printf
#define va_start(v,l) __builtin_va_start(v,l)
#define va_arg(v,l)   __builtin_va_arg(v,l)
#define va_end(v)     __builtin_va_end(v)
#define va_copy(d,s)  __builtin_va_copy(d,s)
typedef __builtin_va_list va_list;

#endif //__KLIBC_H__

