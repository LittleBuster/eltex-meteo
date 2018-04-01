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

#include "webclient.h"
#include "configs.h"

#include <assert.h>


WebClient::WebClient(HTTPClient *client): client_(client)
{
    assert(client != nullptr);
}

void WebClient::sendSensorsData(int temp, int hum, int pres, int gas)
{
    String outUrl;

    outUrl = CFG_REMOTE_ADDR "/meteo?act=add_meteo&temp=" + String(temp) + 
             "&hum=" + String(hum) + "&pres=" + String(pres) + "&gas=" + String(gas);

    client_->begin(outUrl);
    client_->GET();
    client_->end();
}