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

#include "pages.h"


void PagesIndexBuild(int temp, int hum, String &page)
{
    page = "<html> \
                <body> \
                    <center> \
                    <h1>Eltex Switch Managment</h1><br> \
                    <h2>Temp: " + String(temp) + "*C</h2><br> \
                    <h2>Hum: " + String(hum) + "%</h2><br> \
                    </center> \
                </body> \
            </html>";
}

void PagesNotFoundBuild(String &page)
{
    page = "<html> \
                <body> \
                    <h1>404<br>Not Found</h1> \
                </body> \
            </html>";
}