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
 * @brief Main file for the C1M1V7 Video Demos
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
  uint8_t foo __attribute__((aligned(4)));
  uint8_t * MSB_ptr;
  uint8_t * LSB_ptr;

  ex_struct_alligned_t str3;
  uint16_t half_word = 0xF924;
  uint32_t word = 0xABCD1234;

  printf("Data/Structure Sizes:\n");
  printf("  Aligned uint8_t Variable: %d\n",sizeof(foo));
  printf("                    Packed: %d\n", sizeof(ex_struct_packed_t));
  printf("                   Aligned: %d\n", sizeof(ex_struct_alligned_t));
  printf("           Aligned Members: %d\n",
         sizeof(ex_members_alligned_4_t));
  printf("                 Aligned-8: %d\n", sizeof(ex_struct_alligned_8_t));
  printf("                Aligned-16: %d\n", sizeof(ex_struct_alligned_16_t));
  
  LSB_ptr = (uint8_t*)(&half_word);
  MSB_ptr = ((uint8_t*)(&half_word)) + 1;

  printf("Byte swap 16-bit Integer\n");
  printf("  Half-Word Actual Value: 0x%x\n",half_word);
  printf("  Little Endian Representation:\n");
  printf("    LSB: 0x%x   MSB: 0x%x\n", *LSB_ptr, *MSB_ptr);
  printf("  Big Endian Representation:\n");
  printf("    LSB: 0x%x   MSB: 0x%x\n", *MSB_ptr, *LSB_ptr);
  printf("  Before Swap: 0x%x \n", half_word);
  byte_swap16(&half_word);
  printf("  After Swap: 0x%x \n", half_word);
  byte_swap16(&half_word);


  LSB_ptr = (uint8_t*)(&word);
  MSB_ptr = ((uint8_t*)(&word)) + 1;

  printf("Byte swap 32-bit Integer\n");
  printf("  Word Actual Value: 0x%x\n",word);
  printf("  Little Endian Representation:\n");
  printf("    LSB: 0x%x   MSB: 0x%x\n", *LSB_ptr, *MSB_ptr);
  printf("  Big Endian Representation:\n");
  printf("    LSB: 0x%x   MSB: 0x%x\n", *MSB_ptr, *LSB_ptr);
  printf("  Before Swap: 0x%x \n", word);
  byte_swap32(&word);
  printf("  After Swap: 0x%x \n", word);

  ex_members_alligned_4_t why;
  printf(" %d \n", sizeof(why.x));
  printf(" %d \n", &str3);
  printf(" %d \n", &str3.x);
  printf(" %d \n", &str3.y);
  printf(" %d \n", &str3.z);
}

