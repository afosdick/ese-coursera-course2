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
 * @file swap.c
 * @brief Byte Swap function to convert between different endianness
 *
 * This implementation file provides the implementation of the byte swap
 * funtion used in the class videos for both 16 and 32 bit data types.
 *
 * @author Alex Fosdick
 * @date April 15 2017
 *
 */

#include <stdint.h>
#include <stdio.h>
#include "swap.h"


void byte_swap32(uint32_t * word){
  uint8_t temp, i;

  for( i = 0; i <  2; i++) {
    temp = *((uint8_t*)word + (3 - i));
    *( ((uint8_t*)word) + (3 - i)) = *((uint8_t*)word + i);
    *((uint8_t*)word + i) = temp;
  }

  return;

}

#pragma GCC push
#pragma GCC optimize ("O2")
void byte_swap16(uint16_t * halfword){
  uint8_t temp;

  temp = *((uint8_t*)halfword + 1);
  *( ((uint8_t*)halfword) + 1 ) = *((uint8_t*)halfword);
  *((uint8_t*)halfword) = temp;

  return;
}
#pragma GCC pop
