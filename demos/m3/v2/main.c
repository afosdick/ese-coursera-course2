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
#include "ball.h"

void main(){


  printf("Sizeof Struct with Bit Fields: %lu\n", sizeof(ex1));
  printf("Sizeof Struct with Bit Fields and Alignment: %lu\n", sizeof(ex2));
  printf("Sizeof Struct with Bit Fields and Members: %lu\n",sizeof(ex3));

  printf("Value of Bit Fields:\n");
  printf("x value: %u\n", ex1.x);
  printf("y value: %u\n", ex1.y);
  printf("z value: %u\n", ex1.z);

}

