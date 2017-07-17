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
 * @brief Main file for the C2M3V3 Video Demos
 *
 * @author Alex Fosdick
 * @date June 6 2017
 *
 */

#include <stdint.h>
#include <stdio.h>
#include "enum.h"

#define MAX_ARRAY (4)

void main(){
  uint8_t i;
  month m = APRIL;

  printf("Sizeof(month): %ld Bytes\n", sizeof(month));
  printf("Sizeof(Num_e): %ld Bytes\n", sizeof(Num_e));
  printf("Sizeof(Boolean_e): %ld Bytes\n", sizeof(Boolean_e));
  printf("Sizeof(Error_e): %ld Bytes\n", sizeof(Error_e));
  printf("Sizeof(CB_e): %ld Bytes\n", sizeof(CB_e));

  uint8_t array[MAX_ARRAY] = {0, 1, 2, 3};
  CB_e err;
 
  array[-1] = 8;

  printf("Example Array Indexing\n");
  printf("  Array[-1] = %d\n", array[-1]);
  printf("  &Array = %p\n", &array);
  printf("  &Array[-1] = %p\n", &array[-1]);

  for ( i = 0; i < MAX_ARRAY; i++ )
  {
    printf("  Array[%d] = %d\n", i, array[i]);
  }

}

