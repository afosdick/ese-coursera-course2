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
 * @brief Main file for the C1M1V5 Video Demos
 *
 * @author Alex Fosdick
 * @date April 15 2017
 *
 */

#include <stdint.h>
#include <stdio.h>
#include "struct.h"

void main(){

  ex_normal_t str0;
  ex_packed_t str1;
  ex_fast_t str2;
  
  printf("Sizeof Normal Struct: %d\n", sizeof(str0));
  printf("Sizeof Packed Struct: %d\n", sizeof(str1));
  printf("Sizeof Fast Struct: %d\n",sizeof(str2));

  printf("str0 address: %u\n", (uint32_t)(&(str0)));
  printf("x address: %u\n", (uint32_t)(&(str0.x)));
  printf("y address: %u\n", (uint32_t)(&(str0.y)));
  printf("z address: %u\n", (uint32_t)(&(str0.z)));

  printf("str1 address: %u\n", (uint32_t)(&(str1)));
  printf("x address: %u\n", (uint32_t)(&(str1.x)));
  printf("y address: %u\n", (uint32_t)(&(str1.y)));
  printf("z address: %u\n", (uint32_t)(&(str1.z)));

  printf("str2 address: %u\n", (uint32_t)(&(str2)));
  printf("x address: %u\n", (uint32_t)(&(str2.x)));
  printf("y address: %u\n", (uint32_t)(&(str2.y)));
  printf("z address: %u\n", (uint32_t)(&(str2.z)));

}

