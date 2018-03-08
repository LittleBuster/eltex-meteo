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

#ifndef CONFIGS_H
#define CONFIGS_H

#include <Arduino.h>


#define CFG_WIFI_SSID ""
#define CFG_WIFI_PASSWD ""


#define CFG_DNS_NAME "EspEltex"


#define CFG_METEO_DELAY 30
#define CFG_INFO_DELAY 10


#define CFG_SERVER_PORT 80


#define CFG_INDEX_HANDLER "/"


#define CFG_STATUS_LED 2


#define CFG_SCL_PIN D1
#define CFG_SDA_PIN D2
#define CFG_DHT_PIN D3


#define CFG_LCD_ADDR 0x3F
#define CFG_LCD_WDTH 16
#define CFG_LCD_HGHT 2


#endif