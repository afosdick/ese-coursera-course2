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

typedef struct {
  char x;
  int y;
  char z;
} ex_normal_t ;

typedef struct {
  int_fast8_t x;
  int_fast32_t y;
  int_fast8_t z;
} ex_fast_t ;

typedef struct {
  int8_t x;
  int32_t y;
  int8_t z;
} __attribute__((aligned)) ex_packed_t ;

typedef struct {
  uint8_t x;
  uint32_t y;
  uint8_t z;
} __attribute__((packed)) ex_struct_packed_t ;

typedef struct {
  uint8_t x;
  uint32_t y;
  uint8_t z;
} __attribute__((aligned)) ex_struct_alligned_t ;

typedef struct {
  uint8_t x __attribute__((aligned(4)));
  uint32_t y __attribute__((aligned(4)));
  uint8_t z __attribute__((aligned(4)));
}  ex_members_alligned_4_t;

typedef struct {
  uint8_t x;
  uint32_t y;
  uint8_t z;
} __attribute__((aligned(8))) ex_struct_alligned_8_t;

typedef struct {
  uint8_t x;
  uint32_t y;
  uint8_t z;
} __attribute__((aligned(16))) ex_struct_alligned_16_t;


#endif /* __STRUCT_H__ */
