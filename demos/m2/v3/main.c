/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 * 
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material.
 * 
 ******************************************************************************/
/**
 * @file main.c
 * @brief c2m2v8 Port Pin Configuration Demo
 *
 * This file is used for a live demo of configuring a simple port pin using CCS
 * and the msp432 micrcontroller.
 *
 * @author Alex Fosdick
 * @date May 28 2017
 *
 */

#include <stdint.h>
#include "msp.h"

#define LENGTH1 (100000)
#define LENGTH2 (10000)

#define P1_OUT_REG (0x40004C02)
#define P1_DIR_REG (0x40004C04)
#define BIT_0 (0x01)

void main(void)
{

  uint32_t i;
  //uint8_t * p1_out = (uint8_t*)P1_OUTPUT_REG; /* pointer to port 1 output register */
  //uint8_t * p1_dir = (uint8_t*)P1_DIR_REG; /* pointer to port 1 direction register */

  /* Stop watchdog timer */
  WDTCTL = WDTPW | WDTHOLD;

  /* Structure Overlay: Configure P1.0 as output */
  P1->DIR |= BIT_0;

  /* Direct Dereference: Configure P1.0 as output */
  //*p1_dir |= BIT_0;

  /* Code to show LED blinking on and off */
  while(1)
  {
  /* Structure Overlay: Toggle P1.0 */
  P1->OUT ^= BIT_0;

  /* Direct Dereference: Toggle P1.0 */
  //*p1_out ^= BIT_0;

  for( i = LENGTH2; i > 0; i--);      /* Delay */
                                                         	                    }
}                                                        	                    }
