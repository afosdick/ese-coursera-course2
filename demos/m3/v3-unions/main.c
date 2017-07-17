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
#include "union.h"
#include "ball.h"

void main(){
  uint8_t i;
  ex_Std_8_u ex1;
  ex_Std_u ex2;
  ex_Structs_u ex3;

  APSR_Type apsr;

  /* Interfacing with the APSR through two union methods:
      1) Through the full register word
      2) Through individual bit fields 
  */
  apsr.w = 0xFFFFFFFF;
  apsr.b.V = 0;
  apsr.b.C = 0;
  apsr.b.Z = 0;
  apsr.b.N = 0;
  
  printf("APSR: %x\n",apsr.w);

  printf("Sizeof Union Members same size sizeof(ex_Std_8_u): %lu\n", sizeof(ex1));
  printf("  Address of the ex1 Union: %p\n", &ex1);
  printf("  Address of the ex1.x: %p\n", &ex1.x);
  printf("  Address of the ex1.y: %p\n", &ex1.y);
  printf("  Address of the ex1.z: %p\n", &ex1.z);

  printf("Sizeof Union Different Sized Members sizeof(ex_Std_u): %lu\n", sizeof(ex1));
  printf("  Address of the ex2 Union: %p\n", &ex2);
  printf("  Address of the ex2.array: %p\n", &ex2.array);
  printf("  Address of the ex2.x: %p\n", &ex2.x);
  printf("  Address of the ex2.y: %p\n", &ex2.y);
  printf("  Address of the ex2.z: %p\n", &ex2.z);
  
  printf("Sizeof Union with two structus sizeof(ex_Structs_U): %lu\n", sizeof(ex3));
  printf("  sizeof(ex_Structs_u -> Str1_t): %lu\n", sizeof(ex3.a));
  printf("  sizeof(ex_Structs_u -> Str2_t): %lu\n", sizeof(ex3.b));
  printf("  Address of the ex3 Union: %p\n", &ex1);
  printf("  Address of the ex3.a: %p\n", &ex3.a);
  printf("  Address of the ex3.a: %p\n", &ex3.b);

  ex1.x = 13;
  printf("ex1.x = 13\n");
  printf("  ex1 -> x = %d   y = %d   z = %d\n",ex1.x, ex1.y, ex1.z);
  ex1.y = 65;
  printf("ex1.y = 65\n");
  printf("  ex1 -> x = %d   y = %d   z = %d\n",ex1.x, ex1.y, ex1.z);
  ex1.z = 81;
  printf("ex1.z = 81\n");
  printf("  ex1 -> x = %d   y = %d   z = %d\n",ex1.x, ex1.y, ex1.z);

  for ( i = 0; i < 16; i++) 
  {
    ex2.array[i] = 0;
  }
  ex2.array[0] = 12;
  printf("ex2.array[0] = 12\n");
  printf("  ex2 -> x = %d   y = %d   z = %d\n",ex2.x, ex2.y, ex2.z);

  ex3.a.x = 9;
  printf("ex3.b.x = 9\n");
  printf("  ex3.a -> x = %d   y = %d   z = %d\n",ex3.a.x, ex3.a.y, ex3.a.z);
  printf("  ex3.b -> x = %d   y = %d   z = %d\n",ex3.b.x, ex3.b.y, ex3.b.z);
  ex3.b.x = 257;
  printf("ex3.b.x = 257\n");
  printf("  ex3.a -> x = %d   y = %d   z = %d\n",ex3.a.x, ex3.a.y, ex3.a.z);
  printf("  ex3.b -> x = %d   y = %d   z = %d\n",ex3.b.x, ex3.b.y, ex3.b.z);

}

