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
 * @brief c2m2v8 Debugger Demo
 *
 * This file is used for a live demo of CCS and the debugger environment
 * inconjunction with the Course 2 Module 2 Video 8 of the coursera course
 * on Embedded Software and Hardware Architecture
 *
 * @author Alex Fosdick
 * @date May 28 2017
 *
 */

#include <stdint.h>
#include "msp.h"
#include "memory.h"

/* Constants */
#define ARRAY_MAX (16)
#define MEMOVE_LENGTH (8)
#define LENGTH1 (100000)
#define LENGTH2 (10000)

/* Function Prototype for an simple led blink function that does not return */
void blink_led_forever();

/* Source Array for memory move */
uint8_t array1 [ARRAY_MAX];

/* Destination Array for memory move */
uint8_t array2 [ARRAY_MAX];

void main(void)
{
    volatile uint32_t i = 0;

    /* Stop watchdog timer */
    WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;

    /* Configure P1.0 as output */
    P1->DIR |= BIT0;

    /* Initialize Memory for a Memory Dump Debugging Example */
    for( i = 0; i < ARRAY_MAX; i++)
    {
        array1[i] = i;
    }
    my_memset(array2, ARRAY_MAX, 0xff);

    /* Create a NOP instruction for a breakpoint */
    __NOP();

    my_memmove(array1, array2, MEMOVE_LENGTH);  /* Missing Semicolon */

    /* Create a NOP instruction for a breakpoint */
    __NOP();

    /* This code will NOT return */
    blink_led_forever();

}

void blink_led_forever()
{
   uint32_t i;

   /* Code to show LED blinking on and off */
   while(1)
   {
       P1->OUT ^= BIT0;                    /* Toggle P1.0 */
       for( i = LENGTH1; i > 0; i--);      /* Delay */
   }
}
