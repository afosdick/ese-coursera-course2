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

  ex_BF_t ex1;
  ex_BF_OVF_t ex2;
  ex_BF_0_t ex3;
  ex_BF_MEM_t ex4;
  APSR_Type apsr;

  apsr.w = 0xFFFFFFFF;
  apsr.b.V = 0;
  apsr.b.C = 0;
  apsr.b.Z = 0;
  apsr.b.N = 0;
  
  printf("APSR: %x\n",apsr.w);

  ex1.x = 4;
  ex1.y = 3;
  ex1.z = 1;

  ex2.x = 5;
  ex2.y = 63;
  ex2.z = 6;

  printf("Sizeof Struct with Bit Fields: %lu\n", sizeof(ex1));
  printf("Sizeof Struct with Bit Fields that overflow into next Members: %lu\n"
         , sizeof(ex2));
  printf("Sizeof Struct with Bit Fields and Alignment: %lu\n", sizeof(ex3));
  printf("Sizeof Struct with Bit Fields and Members: %lu\n",sizeof(ex4));

  printf("Value of Bit Fields ex1:\n");
  printf("  x value: %u\n", ex1.x);
  printf("  y value: %u\n", ex1.y);
  printf("  z value: %u\n", ex1.z);

  printf("Bit Field Order for ex1:\n");
  printf("    ==> 0x%x \n", (*((uint8_t*)(&ex1))));
  printf("Bit Fields start at LSB and grow to MSB:\n");
  printf("    (*(uint8_t*)(&ex1)) & 0x07 \n");
  printf("        ==> %x \n", (*((uint8_t*)(&ex1)) & 0x07) );

  printf("Value of Bit Fields that overflow ex2:\n");
  printf("  x value: %u\n", ex2.x);
  printf("  y value: %u\n", ex2.y);
  printf("  z value: %u\n", ex2.z);

  printf("Bit Field Order for ex2:\n");
  printf("  0x%x ", (*((uint8_t*)(&ex2))));
  printf("  (*(uint8_t*)(&ex2)) & 0x1F \n");
  printf("        ==> %u \n", (*((uint8_t*)(&ex2)) & 0x1F) );

  printf("  0x%x ", (*(((uint8_t*)(&ex2))+1)));
  printf("  (*(uint8_t*)(&ex1)) & 0x3F \n");
  printf("        ==> %u \n", (*(((uint8_t*)(&ex2)+1)) & 0x3F) );

  printf("  0x%x ", (*(((uint8_t*)(&ex2))+2)));
  printf("  (*(uint8_t*)(&ex1)) & 0x1F \n");
  printf("        ==> %u \n", (*(((uint8_t*)(&ex2))+2) & 0x1F) );
}

