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

#include "sensors.h"
#include "configs.h"

#include <assert.h>


float Sensors::convertToHg(float pres)
{
    return (pres * 750) / 100000;
}


Sensors::Sensors(IBmp280 *bmp, IDht *dht, IMq135 *mq): bmp_(bmp), dht_(dht), mq_(mq)
{
    assert(bmp != nullptr);
    assert(dht != nullptr);
    assert(mq != nullptr);
}

void Sensors::setup()
{
    dht_->setup(CFG_DHT_PIN, DHT22);
    mq_->setPin(CFG_GAS_PIN);
    if (!bmp_->begin())
        while (1);
}

float Sensors::getPressure()
{
    return convertToHg(bmp_->readPressure());
}

void Sensors::getTempHum(float &temp, float &hum)
{
    dht_->getTempAndHumidity(temp, hum);
}

float Sensors::getGasPPM(float temp, float hum)
{
    return mq_->getCorrectedPPM(temp, hum);
}