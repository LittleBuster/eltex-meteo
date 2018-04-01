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

package com.denfnd;


import com.denfnd.http.*;
import com.denfnd.modules.meteo.Meteo;
import com.denfnd.modules.meteo.MeteoStation;
import com.denfnd.utils.*;


public class Main {

    public static void main(String[] args) {
        Logger log = new Log();
        Configurable cfg = new Configs();
        Server wserver = new WebServer();
        Locker locker = new MutexLocker();
        Meteo meteo = new MeteoStation(locker);
        Maker hmaker = new HandlersMaker(log, meteo);
        Application app = new Application(log, cfg, wserver, hmaker);

        app.start();
    }
}
