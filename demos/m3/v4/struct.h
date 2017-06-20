/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/** 
 * @file struct.h
 * @brief Definitions of example aligned data structures for C2M1V5 demos
 *
 * @author Alex Fosdick
 * @date April 15 2017
 *
 */
#ifndef __STRUCT_H__
#define __STRUCT_H__

#include <stdint.h>

typedef union
{
  struct
  {
    uint32_t _reserved0:16;   /*!< bit:  0..15  Reserved */
    uint32_t GE:4;            /*!< bit: 16..19  Greater than or Equal flags */
    uint32_t _reserved1:7;    /*!< bit: 20..26  Reserved */
    uint32_t Q:1;             /*!< bit:     27  Saturation condition flag */
    uint32_t V:1;             /*!< bit:     28  Overflow condition code flag */
    uint32_t C:1;             /*!< bit:     29  Carry condition code flag */
    uint32_t Z:1;             /*!< bit:     30  Zero condition code flag */
    uint32_t N:1;             /*!< bit:     31  Negative condition code flag */
  } b;                        /*!< Structure used for bit  access */
  uint32_t w;                 /*!< Type      used for word access */
} APSR_Type;


typedef struct {
  uint8_t x : 3;
  uint8_t y : 2;
  uint8_t z : 1;
} ex_BF_t ;

typedef union {
  uint8_t x : 3;
  uint8_t y : 2;
  uint8_t z : 1;
} ex_BF_u ;

typedef struct {
  uint8_t x : 5;
  uint8_t y : 6;
  uint8_t z : 5;
} ex_BF_OVF_t ;

typedef struct {
  uint32_t x : 16;
  uint32_t y : 4;
  uint32_t :0;
  uint32_t z : 10;
} ex_BF_0_t ;

typedef struct {
  uint8_t x : 3;
  uint8_t y : 4;
  uint16_t z;
} __attribute__((packed)) ex_BF_MEM_t ;

#ifdef SHOW_ERROR
typedef struct {
  uint8_t x : 9;
  uint8_t y : 4;
  uint8_t z : 4;
} ex_ERROR_t ;
#endif

#endif /* __STRUCT_H__ */
