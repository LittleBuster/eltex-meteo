/*****************************************************************************
 *
 * Eltex Meteo Project
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


#include "lcd_i2c.h"

#include <Arduino.h>


static uint8_t tempCel[8] = { B11100,
                              B10100,
                              B11100,
                              B00000,
                              B00000,
                              B00000,
                              B00000 };


class IDisplay
{
public:
    virtual void setup() = 0;
    virtual void printSensorsData(int temp, int hum, int pres, int gas) = 0;
};


class Display: public IDisplay
{
public:
    Display(ILcdI2c *lcd);

    /**
     * Display settings
     */
    void setup();

    /**
     * Print sensors data
     *
     * @param temp Room temperature
     * @param hum Room humidity
     * @param pres Atmospheric pressure
     * @param gas Room gasses PPM
     */
    void printSensorsData(int temp, int hum, int pres, int gas);

private:
    ILcdI2c *lcd_;
};


#endif