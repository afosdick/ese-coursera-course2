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
 * @file main.c
 * @brief Main file for the C1M1V6 Video Demos on Endianness
 *
 * @author Alex Fosdick
 * @date April 15 2017
 *
 */

#include <stdint.h>
#include <stdio.h>
#include "swap.h"
#include "struct.h"

void main(){
  uint8_t * MSB_ptr;
  uint8_t * LSB_ptr;
  uint16_t array[4] = { 0x1234, 0x4567, 0x89AB, 0xCDEF}; 
  uint16_t half_word = 0xF924;
  uint32_t word = 0xABCD1234;
  
  LSB_ptr = (uint8_t*)(&half_word);
  MSB_ptr = ((uint8_t*)(&half_word)) + 1;

  printf("Array[4] of 16-bit Integers\n");
  printf("  [0]  LSB: 0x%x   MSB: 0x%x\n", *(uint8_t*)(&array[0]),
                                           *(((uint8_t*)(&array[0]))+1));
  printf("  [1]  LSB: 0x%x   MSB: 0x%x\n", *(uint8_t*)(&array[2]),
                                           *(((uint8_t*)(&array[2]))+1));
  printf("  [2]  LSB: 0x%x   MSB: 0x%x\n", *(uint8_t*)(&array[3]),
                                           *(((uint8_t*)(&array[3]))+1));
  printf("  [3]  LSB: 0x%x   MSB: 0x%x\n", *(uint8_t*)(&array[4]),
                                           *(((uint8_t*)(&array[4]))+1));
    

  printf("Byte swap 16-bit half-word Integer\n");
  printf("  Value: 0x%x\n",half_word);
  printf("    Little Endiann:\n");
  printf("       LSB: 0x%x   MSB: 0x%x\n", *LSB_ptr, *MSB_ptr);
  printf("    Big Endian:\n");
  printf("       LSB: 0x%x   MSB: 0x%x\n", *MSB_ptr, *LSB_ptr);
  printf("  Before Swap: 0x%x \n", half_word);
  byte_swap16(&half_word);
  printf("  After Swap: 0x%x \n", half_word);
  byte_swap16(&half_word);


  LSB_ptr = (uint8_t*)(&word);
  MSB_ptr = ((uint8_t*)(&word)) + 1;

  printf("Byte swap 32-bit Word Integer\n");
  printf("  Value: 0x%x\n",word);
  printf("    Little Endian:\n");
  printf("       LSB: 0x%x   MSB: 0x%x\n", *LSB_ptr, *MSB_ptr);
  printf("    Big Endian:\n");
  printf("       LSB: 0x%x   MSB: 0x%x\n", *MSB_ptr, *LSB_ptr);
  printf("  Before Swap: 0x%x \n", word);
  byte_swap32(&word);
  printf("  After Swap: 0x%x \n", word);
}

