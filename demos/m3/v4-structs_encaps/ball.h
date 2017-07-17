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
 * @file ball.h
 * @brief Example data structures assocatioted with ball movemen
 *
 * @author Alex Fosdick
 * @date June 6 2017
 *
 */
#ifndef __BALL_H__
#define __BALL_H__

#include <stdint.h>
#include <time.h>

#define MAX_NUMBER_MOVES (10)

typedef struct {
  uint32_t x;
  uint32_t y;
  uint32_t z;
} Point_t;


typedef struct {
  Point_t xyz;
  time_t time;
} Position;

typedef struct {
  Movement points[MAX_NUMBER_MOVES];
  uint32_t number;
} Ball;

/**
 * @brief Adds a Data point to a Ball Position Data Structure
 * 
 * This function will add X, Y, Z, and Time data into a Ball Position
 * Data structure. This will increment the current count of positions
 * recorded. If the Maximum number of recordings have been reached, this
 * will skip adding the newest data point.
 *
 * @return void
 */
void add_move (Ball * ball, Location * loc);

/**
 * @brief Removes all data from a Ball Data structure.
 * 
 * This function will remove all data collected for a particual ball.
 *
 * @return void
 */
void clear_movements (Ball * ball);

/**
 * @brief Calculates the instantaneous velocity of a ball
 * 
 * This function will calculate the velocity of a ball in a dimension given
 *  coordinate pair and a respective time.
 *
 * @return velocity of the ball in plan
 */
int32_t calculate_instantaneous_velocity(uint32_t v0, uint32_t v1, time_t time);


#endif /* __BALL_H__ */
