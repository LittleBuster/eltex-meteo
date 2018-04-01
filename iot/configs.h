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

#define CFG_REMOTE_ADDR "http://127.0.0.1:8080"


#define CFG_METEO_DELAY 30


#define CFG_STATUS_LED 2


#define CFG_DHT_PIN D3
#define CFG_GAS_PIN A0


#define CFG_LCD_ADDR 0x27
#define CFG_LCD_ROWS 16
#define CFG_LCD_COLS 2
#define CFG_LCD_HEAD "     Eltex      "
#define CFG_LCD_BTM  " Meteo Station  "


#endif