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
 * @file platform.h
 * @brief File contains platform and compiler specific defines
 *
 * @author Alex Fosdick
 * @date April 15 2017
 *
 */
#ifndef __PLATFORM_H__
#define __PLATFORM_H__

#ifdef (__STDC__) 
#define INLINE inline
#else
#define INLINE
#endif

#if defined (__GNUC__)
#define __attribute__(x) 

#endif /* __PLATFORM_H__ */
