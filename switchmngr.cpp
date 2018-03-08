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

#include "switchmngr.h"
#include "switchsrv.h"
#include "wifimngr.h"
#include "meteo.h"
#include "display.h"
#include "info.h"


void SwitchMngrSetup(void)
{
    WifiMngrSetup();
    SwitchServerSetup();
    DisplaySetup();
    MeteoSetup();
    InfoSetup();
}

void SwitchMngrLoop(void)
{
    SwitchServerLoop();
    MeteoLoop();
    InfoLoop();
}