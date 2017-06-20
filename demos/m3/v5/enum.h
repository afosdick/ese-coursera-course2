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
  CB_NOERROR,
  CB_EMPTY,
  CB_FULL,
  CB_NULL,
  CB_END,
} CB_e ;


#endif /* __ENUM_H__ */
