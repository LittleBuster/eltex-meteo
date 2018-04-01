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

package com.denfnd.http;


import com.denfnd.http.handlers.*;
import com.denfnd.modules.meteo.Meteo;
import com.denfnd.utils.Configurable;
import com.denfnd.utils.Logger;
import com.sun.net.httpserver.HttpHandler;


public class HandlersMaker implements Maker {
    private Logger log;
    private Meteo meteo;

    public HandlersMaker(Logger log, Meteo meteo) {
        this.log = log;
        this.meteo = meteo;
    }

    public HttpHandler makeHandler(String name) {
        if (name.equals("index"))
            return new IndexHandler(log, meteo);
        if (name.equals("meteo"))
            return new MeteoHandler(log, meteo);
        if (name.equals("css"))
            return new FileHandler(log);
        return null;
    }
}
