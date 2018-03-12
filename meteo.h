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

#ifndef METEO_H
#define METEO_H


/**
 * @brief Meteo module initialize
 */
void MeteoSetup(void);

/**
 * @brief Meteo module main loop
 */
void MeteoLoop(void);

/**
 * @brief Get meteo data from sensor
 *
 * @param[out] temp Temperature from sensor
 * @param[out] hum Humidity from sensor
 * @param[out] pres Pressure from sensor
 * @param[out] gas Gasses from sensor
 */
void MeteoGetData(int &temp, int &hum, int &pres, int &gas);


#endif