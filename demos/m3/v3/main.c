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
#include "struct.h"

void main(){

  ex_Std_8_u ex1;
  APSR_Type apsr;

  apsr.w = 0xFFFFFFFF;
  apsr.b.V = 0;
  apsr.b.C = 0;
  apsr.b.Z = 0;
  apsr.b.N = 0;
  
  printf("APSR: %x\n",apsr.w);

  printf("Sizeof Union Standard Byte: %lu\n", sizeof(ex1));
  printf("Address of the ex1 Union: %p\n", &ex1);
  printf("Address of the ex1.x: %p\n", &ex1.x);
  printf("Address of the ex1.y: %p\n", &ex1.y);
  printf("Address of the ex1.z: %p\n", &ex1.z);


  ex1.x = 13;
  printf("ex1 -> x = %d   y = %d   z = %d\n",ex1.x, ex1.y, ex1.z);
  ex1.y = 65;
  printf("ex1 -> x = %d   y = %d   z = %d\n",ex1.x, ex1.y, ex1.z);
  ex1.z = 81;
  printf("ex1 -> x = %d   y = %d   z = %d\n",ex1.x, ex1.y, ex1.z);
}

