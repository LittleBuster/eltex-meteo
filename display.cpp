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

#include "display.h"
#include "configs.h"

#include <LiquidCrystal_I2C.h>
#include <Wire.h>


static LiquidCrystal_I2C lcd(CFG_LCD_ADDR, CFG_LCD_WDTH, CFG_LCD_HGHT);
static uint8_t tempCel[8] = { B11100,
                              B10100,
                              B11100,
                              B00000,
                              B00000,
                              B00000,
                              B00000 };


void DisplaySetup(void)
{
    Wire.begin(CFG_SDA_PIN, CFG_SCL_PIN);
    lcd.begin();
    lcd.createChar(1, tempCel);
    lcd.home();
    lcd.clear();

    lcd.print("      Eltex");
    lcd.setCursor(0, 1);
    lcd.print("  Switch  Mgmt");
}

void DisplayShowInfo(int temp, int hum)
{
    String tempStr = "Temperature: " + String(temp);
    String humStr = "Humidity:    " + String(hum) + "%";

    lcd.clear();
    lcd.print(tempStr);
    lcd.print("\1");
    lcd.setCursor(0, 1);
    lcd.print(humStr);
}