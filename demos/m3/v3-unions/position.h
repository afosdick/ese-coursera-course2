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
 * @file position.h
 * @brief Example data structures assocatioted with position and velocity.
 *
 * @author Alex Fosdick
 * @date June 6 2017
 *
 */
#ifndef __POSITION_H__
#define __POSITION_H__

#include <stdint.h>
#include <time.h>

/* This Data structure tracks the position of an item in 3D space. Data is
   is collected from an external sensor and the X, Y, & Z position are filled
   in correspondingly. For each Ball position, you need to track the time 
   the locaiton was recorded using a timestamp */
typedef struct {
  int32_t x;
  int32_t y;
  int32_t z;
  time_t time;
} Position_t;

typedef struct {
  int32_t v_x;
  int32_t v_y;
  int32_t v_z;
} Velocity_t;

/**
 * @brief Calculates the instantaneous velocity of a item
 * 
 *  This function will calculate the velocity of a item in a dimension given a
 *  coordinate pair with respective time stamps.
 *
 * @return velocity of the item in plane
 */
Velocity_t calculate_instantaneous_velocity(Position_t * pos0,
                                            Position_t * pos1);

#endif /* __POSITION_H__ */
