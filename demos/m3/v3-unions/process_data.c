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
 * @file process_data.c
 * @brief Supplemental file for the C2M3V3 Video Demos
 *
 * @author Alex Fosdick
 * @date June 6 2017
 *
 */

#include <stdint.h>
#include <stdlib.h>
#include "position.h"

#define UART_BUF_SIZE (512)
#define POINTS_BUF_SIZE (32)

/* Union of shared memory */
typedef union {
  uint8_t uart_buf[UART_BUF_SIZE];
  Position_t pos_buf[POINTS_BUF_SIZE];
} Buf_t;

void process_Movement(Position_t * pos, size_t points);
void process_UARTDATA(uint8_t * buf, size_t length);

void main() {
  Buf_t * buf;
  buf = (Buf_t *) malloc(sizeof(Buf_t));

  while (1)
  {
    process_UARTDATA(buf->uart_buf, UART_BUF_SIZE);
    process_Movement(buf->pos_buf, POINTS_BUF_SIZE);
  }
}

/* Count then number of numeric characters in the buffer */
void process_UARTDATA(uint8_t * buf, size_t length)
{
  uint32_t count, i;
  for (i = 0; i < length; i++)
  {
    if (buf[i] >= '0' && buf[i] <= '9')
    {
      count++;
    }
  }
  /* More processing here */
}

/* Calculate the instantaneous velocity for each move of a ball in X,Y & Z */
void process_Movement(Position_t * pos, size_t points)
{
  Velocity_t velocity;
  uint32_t count, i;

  for (i = 0; i < points - 1; i++)
  {
    velocity = calculate_instantaneous_velocity( &pos[i], &pos[i+1] );
    /* More processing here */
  }
  /* More processing here */
}

