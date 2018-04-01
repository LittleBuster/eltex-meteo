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

#include <eltex_meteo.h>


Bmp280 bmp;
Mq135 mq;
Dht dht;
LcdI2c lcd;
HTTPClient http;
WebClient client(&http);
Display display(&lcd);
Sensors sensors(&bmp, &dht, &mq);
EltexMeteo meteo(&sensors, &display, &client);


void setup()
{
    meteo.setup();
}

void loop()
{
    meteo.loop();
}