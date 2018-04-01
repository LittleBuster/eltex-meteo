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

#include "display.h"
#include "configs.h"

#include <assert.h>


Display::Display(ILcdI2c *lcd): lcd_(lcd)
{
    assert(lcd != nullptr);
}

void Display::setup()
{
    lcd_->setAddress(CFG_LCD_ADDR);
    lcd_->setResolution(CFG_LCD_COLS, CFG_LCD_ROWS);
    lcd_->begin();
    lcd_->createChar(1, tempCel);
    lcd_->setBacklight(true);

    lcd_->setCursor(0, 0);
    lcd_->print(CFG_LCD_HEAD);
    lcd_->setCursor(0, 1);
    lcd_->print(CFG_LCD_BTM);

    delay(2000);
}

void Display::printSensorsData(int temp, int hum, int pres, int gas)
{
    lcd_->clear();
    lcd_->setCursor(0, 0);

    if (temp > -1 && temp < 10)
      lcd_->print("Temp: " + String(temp));
    else
      lcd_->print("Temp:" + String(temp));
    lcd_->print("\1");
    lcd_->print(" P:" + String(pres) + "mm");

    lcd_->setCursor(0, 1);
    if (hum < 10)
      lcd_->print("Humd: " + String(hum) + "%");
    else
      lcd_->print("Humd:" + String(hum) + "%");
    lcd_->print(" G:" + String(gas) + "pp");
}