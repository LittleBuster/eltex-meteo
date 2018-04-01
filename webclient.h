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

#ifndef WEB_CLIENT_H
#define WEB_CLIENT_H

#include <ESP8266HTTPClient.h>


class IWebClient
{
public:
    virtual void sendSensorsData(int temp, int hum, int pres, int gas) = 0;
};


class WebClient: public IWebClient
{
public:
    WebClient(HTTPClient *client);

    /**
     * Send sensors data
     *
     * @param temp Room temperature
     * @param hum Room humidity
     * @param pres Atmospheric pressure
     * @param gas Room gasses PPM
     */
    void sendSensorsData(int temp, int hum, int pres, int gas);

private:
    HTTPClient *client_;
};


#endif