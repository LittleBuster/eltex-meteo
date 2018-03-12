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

#include "meteo.h"
#include "configs.h"

#include <Arduino.h>
#include <DHTesp.h>
#include <Adafruit_BMP280.h>


static DHTesp dht22;
static Adafruit_BMP280 bme;

static unsigned oldTime;
static unsigned meteoCounter;

static int tempData;
static int humData;
static int presData;
static int gasData;


static int calcPressure(int pres)
{
    return (pres * 750) / 100000;
}

static int calcGasses(int gas)
{
    return (gas * 100) / 1024;
}


void MeteoSetup(void)
{
    oldTime = 0;
    meteoCounter = 0;
    tempData = 0;
    humData = 0;
    presData = 0;
    gasData = 0;

    dht22.setup(CFG_DHT_PIN);

    if (!bme.begin()) {
        while (1);
    }

    pinMode(A0, INPUT); //Gasses

    humData = (int)dht22.getHumidity();
    tempData = (int)dht22.getTemperature();
    presData = calcPressure(bme.readPressure());
    gasData = calcGasses(analogRead(A0));
}

void MeteoLoop(void)
{
    unsigned nowTime = millis() / 1000;

    if (meteoCounter == CFG_METEO_DELAY) {
        meteoCounter = 0;
        humData = (int)dht22.getHumidity();
        tempData = (int)dht22.getTemperature();
        presData = calcPressure(bme.readPressure());
        gasData = calcGasses(analogRead(A0));
    }

    if (nowTime != oldTime) {
        oldTime = nowTime;
        meteoCounter++;
    }
}

void MeteoGetData(int &temp, int &hum, int &pres, int &gas)
{
    temp = tempData;
    hum = humData;
    pres = presData;
    gas = gasData;
}