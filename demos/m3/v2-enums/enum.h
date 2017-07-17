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
 * @file enum.h
 * @brief Definitions of example aligned data structures for C2M1V5 demos
 *
 * @author Alex Fosdick
 * @date April 15 2017
 *
 */
#ifndef __ENUM_H__
#define __ENUM_H__

#include <stdint.h>

typedef enum {
  JANUARY = 1,
  FEBRUARY = 2,
  MARCH = 3,
  APRIL = 4,
  MAY = 5,
  JUNE = 6,
  JULY = 7,
  AUGUST = 8,
  SEPTEMBER = 9,
  OCTOBER = 10,
  NOVEMBER = 11,
  DECEMBER = 12,
} month;

typedef enum {
  NEGATIVE_ONE = -1,
  ZERO = 0,
  ONE = 1,
  /* MORE ENUMS*/
  THREE_HUNDRED = 300,
} Num_e;

typedef enum {
  BFALSE = 0,
  BTRUE = 1,
} Boolean_e;

/* These Enumerations will produce errors for reuse of a name defined
   in other header files */
#ifdef SHOW_ERRORS
typedef enum {
  NO_ERROR = 0,
  ERROR,
  SYNC_ERROR,
  POWER_ERROR,
} Error_e;

typedef enum {
  NOERROR,
  ERROR,
  NULL,
  FULL,
  EMPTY,
  END,
} CB_e ;

/* These Enumerations are coded to reduce name reuse by using
   a prefix on each value */
#else
typedef enum {
  ERROR_NONE = 0,
  ERROR_SYNC,
  ERROR_POWER,
  ERROR_MEMORY,
  ERROR_PERIPH,
  ERROR_CLOCK,
  ERROR_DMA,
  ERROR_END,
} Error_e;

typedef enum {
  CB_NOERROR,
  CB_ERROR,
  CB_NULL,
  CB_FULL,
  CB_EMPTY,
  CB_END,
} CB_e ;
#endif

#endif /* __ENUM_H__ */
