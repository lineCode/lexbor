/*
 * Copyright (C) 2018 Alexander Borisov
 *
 * Author: Alexander Borisov <lex.borisov@gmail.com>
 */

#ifndef LEXBOR_TYPES_H
#define LEXBOR_TYPES_H

#ifdef __cplusplus
extern "C" {
#endif

/* Inline */
#ifdef _MSC_VER
    #define lxb_inline static __forceinline
#else
    #define lxb_inline static inline
#endif


/* Simple types */
typedef size_t        lxb_codepoint_t;
typedef unsigned char lxb_char_t;
typedef unsigned int  lxb_status_t;

/* Callbacks */
typedef lxb_status_t (*lexbor_callback_f)(const lxb_char_t *buffer,
                                          size_t size, void *ctx);


#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* LEXBOR_TYPES_H */
