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

#include "info.h"
#include "display.h"
#include "configs.h"
#include "meteo.h"


static unsigned oldTime;
static unsigned infoCounter;


void InfoSetup(void)
{
    int temp, hum, pres, gas;

    oldTime = 0;
    infoCounter = 0;

    delay(3000);
    MeteoGetData(temp, hum, pres, gas);
    DisplayShowInfo(temp, hum, pres, gas);
}

void InfoLoop(void)
{
    unsigned newTime = millis() / 1000;

    if (infoCounter == CFG_INFO_DELAY) {
        int temp, hum, pres, gas;

        infoCounter = 0;

        MeteoGetData(temp, hum, pres, gas);
        DisplayShowInfo(temp, hum, pres, gas);
    }

    if (newTime != oldTime) {
        oldTime = newTime;
        infoCounter++;
    }
}