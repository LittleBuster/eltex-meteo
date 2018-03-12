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

#include "wifimngr.h"
#include "configs.h"

#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266mDNS.h>


void WifiMngrSetup(void)
{
    pinMode(CFG_STATUS_LED, OUTPUT);

    WiFi.softAP(CFG_WIFI_SSID, CFG_WIFI_PASSWD);
    MDNS.begin(CFG_DNS_NAME);
}