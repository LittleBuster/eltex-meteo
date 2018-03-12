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

#include "switchsrv.h"
#include "configs.h"
#include "pages.h"
#include "meteo.h"

#include <Arduino.h>
#include <ESP8266WebServer.h>


static ESP8266WebServer server(CFG_SERVER_PORT);


static void IndexHandler(void)
{
    String page;
    int temp, hum, pres, gas;

    MeteoGetData(temp, hum, pres, gas);
    PagesIndexBuild(temp, hum, pres, gas, page);

    server.send(200, "text/html", page);
}

static void NotFoundHandler(void)
{
    String page;

    PagesNotFoundBuild(page);

    server.send(200, "text/html", page);
}

static void StyleHandler(void)
{
    String page;

    PagesStyleBuild(page);

    server.send(200, "text/css", page);
}

void SwitchServerSetup(void)
{
    server.on(CFG_INDEX_HANDLER, IndexHandler);
    server.on(CFG_STYLE_HANDLER, StyleHandler);
    server.onNotFound(NotFoundHandler);
    server.begin();
}

void SwitchServerLoop(void)
{
    server.handleClient();
}