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
 * @file UNION.h
 * @brief Definitions of example of unions for C2M3V3 demos
 *
 * @author Alex Fosdick
 * @date April 15 2017
 *
 */
#ifndef __UNION_H__
#define __UNION_H__

#include <stdint.h>


/* Union type to access the Interrupt Program Status Register (IPSR). */
typedef union
{
  struct
  {
    uint32_t ISR:9;                      /*!< bit:  0.. 8  Exception number */
    uint32_t _reserved0:23;              /*!< bit:  9..31  Reserved */
  } b;                                   /*!< Structure used for bit  access */
  uint32_t w;                            /*!< Type      used for word access */
} IPSR_Type;

/* Union type to access the Application Program Status Register (APSR). */
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

/*  Union type to access the Control Registers (CONTROL).*/
typedef union
{
  struct
  {
    uint32_t nPRIV:1;    /*!< bit:      0  Execution privilege in Thread mode */
    uint32_t SPSEL:1;         /*!< bit:      1  Stack to be used */
    uint32_t FPCA:1;          /*!< bit:      2  FP extension active flag */
    uint32_t _reserved0:29;   /*!< bit:  3..31  Reserved */
  } b;                        /*!< Structure used for bit  access */
  uint32_t w;                 /*!< Type      used for word access */
} CONTROL_Type;

/* Union with same sized members, all uint8_t */
typedef union {
  uint8_t x;
  uint8_t y;
  uint8_t z;
} ex_Std_8_u ;

/* Union with different sized members */
typedef union {
  uint8_t array[16];
  uint8_t x;
  uint16_t y;
  uint32_t z;
} ex_Std_u ;

typedef struct {
  int8_t x;
  int8_t y;
  int8_t z;
} Str1_t;

typedef struct {
  int32_t x;
  int32_t y;
  int32_t z;
} Str2_t;

/* Union with structures as members, different sizes */
typedef union {
  Str1_t a;
  Str2_t b;
} ex_Structs_u ;


#endif /* __UNION_H__ */
