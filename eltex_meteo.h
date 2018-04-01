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

#ifndef ELTEX_METEO_H
#define ELTEX_METEO_H


#include "sensors.h"
#include "display.h"
#include "webclient.h"


class EltexMeteo
{
public:
    EltexMeteo(ISensors *sensors, IDisplay *display, IWebClient *client);

    /**
     * Meteo settings
     */
    void setup();

    /**
     * Meteo main loop
     */
    void loop();

private:
    ISensors *sensors_;
    IDisplay *display_;
    IWebClient *client_;

    unsigned counter_;
    unsigned oldTime_;
};


#endif