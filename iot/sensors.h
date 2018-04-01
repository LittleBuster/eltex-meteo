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

#ifndef SENSORS_H
#define SENSORS_H


#include "bmp280.h"
#include "dht.h"
#include "mq135.h"


class ISensors
{
public:
    virtual void setup() = 0;
    virtual float getPressure() = 0;
    virtual void getTempHum(float &temp, float &hum) = 0;
    virtual float getGasPPM(float temp, float hum) = 0;
};


class Sensors: public ISensors
{
public:
    Sensors(IBmp280 *bmp, IDht *dht, IMq135 *mq);

    /**
     * Sensors settings
     */
    void setup();

    /**
     * Get atmospheric pressure
     *
     * @return Pressure in mmHg
     */
    float getPressure();

    /**
     * Get room temperature and humidity
     *
     * @param[out] temp Room temperature
     * @param[out] hum Room humidity
     */
    void getTempHum(float &temp, float &hum);

    /**
     * Get room gasses in PPM
     *
     * @param[in] temp Room temperature
     * @param[in] hum Room humidity
     */
    float getGasPPM(float temp, float hum);

private:
    IBmp280 *bmp_;
    IDht *dht_;
    IMq135 *mq_;

    /**
     * Convert atmospheric pressure from Pa to mmHg
     *
     * @param pres Atmospheric pressure in Pa
     *
     * @return Atmospheric pressure in mmHg
     */
    float convertToHg(float pres);
};


#endif