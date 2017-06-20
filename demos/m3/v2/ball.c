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
 * @file ball.c
 * @brief Example data structures assocatioted with ball movement
 *
 * @author Alex Fosdick
 * @date June 6 2017
 *
 */

#include <stdint.h>
#include <time.h>
#include "ball.h"

#define MAX_NUMBER_MOVES (10)

typedef struct {
  uint32_t x;
  uint32_t y;
  uint32_t z;
} Location;


typedef struct {
  Location xyz;
  time_t time;
} Movement;

typedef struct {
  Movement moves[MAX_NUMBER_MOVES];
  uint32_t number;
} Ball;

void add_move (Ball * ball, Location * loc)
{
  /* If the Pointers are NULL, exit */
  if (! ball || ! loc) 
  {
    return;
  }

  /* If we have filled the movement structure, skip adding a new datapoint */
  if (ball->number == MAX_NUMBER_MOVES)
  {
    return;
  }

  /* Copy each data point into the move */
  ball->moves[number].xyz.x = loc->x;
  ball->moves[number].xyz.y = loc->y;
  ball->moves[number].xyz.z = loc->z;

  /* Get a time stamp for the movement */
  ball->moves[number].time = time();

  /* Increment the number of data points added to the structure */
  ball->number++;

}

void clear_movements (Ball * ball)
{
  ball->number = 0;
}

