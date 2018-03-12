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

#ifndef PAGES_H
#define PAGES_H

#include <Arduino.h>


/**
 * @brief Build index page
 *
 * @param[in] temp Temperature from sensor
 * @param[in] hum Humidity from sensor
 * @param[in] pres Pressure from sensor
 * @param[in] gas Gasses from sensor
 * @param[out] page Out html page
 */
void PagesIndexBuild(int temp, int hum, int pres, int gas, String &page);

/**
 * @brief Build 404 page
 *
 * @param[out] page Out html page
 */
void PagesNotFoundBuild(String &page);

/**
 * @brief Build style file
 *
 * @param[out] page Out css file
 */
void PagesStyleBuild(String &page);


#endif