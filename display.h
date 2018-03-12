/*****************************************************************************
 *
 * Eltex Switch Managment Project
 *
 * Copyright (C) 2018 Sergey Denisov.
 * Written by Sergey Denisov aka LittleBuster (DenisovS21@gmail.com)
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public Licence 3
 * as published by the Free Software Foundation; either version 3
 * of the Licence, or (at your option) any later version.
 *
 *****************************************************************************/

#ifndef DISPLAY_H
#define DISPLAY_H


/**
 * @brief Display initialize
 */
void DisplaySetup(void);

/**
 * @brief Show info on display
 *
 * @param temp Temperature from sensor
 * @param hum Humidity from sensor
 * @param pres Pressure from sensor
 * @param gas Gasses from sensor
 */
void DisplayShowInfo(int temp, int hum, int pres, int gas);


#endif