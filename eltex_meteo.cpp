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

#include "eltex_meteo.h"
#include "configs.h"

#include <ESP8266WiFi.h>
#include <assert.h>


EltexMeteo::EltexMeteo(ISensors *sensors,
                       IDisplay *display,
                       IWebClient *client):
                       sensors_(sensors),
                       display_(display),
                       client_(client)
{
    assert(sensors != nullptr);
    assert(display != nullptr);
    assert(client != nullptr);
}

void EltexMeteo::setup()
{
    display_->setup();
    sensors_->setup();

    pinMode(CFG_STATUS_LED, OUTPUT);
    
    WiFi.mode(WIFI_STA);
    WiFi.begin(CFG_WIFI_SSID, CFG_WIFI_PASSWD);

    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        digitalWrite(CFG_STATUS_LED, LOW);
        delay(500);
        digitalWrite(CFG_STATUS_LED, HIGH);        
    }

    counter_ = CFG_METEO_DELAY;
    oldTime_ = 0;
}

void EltexMeteo::loop()
{
    unsigned time = millis() / 1000;
    if (time != oldTime_) {
        oldTime_ = time;
        counter_++;
    }

    if (counter_ >= CFG_METEO_DELAY) {
        float temp = 0, hum = 0, pres = 0, gas = 0;
        counter_ = 0;

        pres = sensors_->getPressure();
        sensors_->getTempHum(temp, hum);
        gas = sensors_->getGasPPM(temp, hum);

        display_->printSensorsData(temp, hum, pres, gas);

        client_->sendSensorsData(temp, hum, pres, gas);
    }
}