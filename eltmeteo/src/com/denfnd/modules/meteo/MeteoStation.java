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

package com.denfnd.modules.meteo;


import com.denfnd.utils.Locker;
import java.util.HashMap;
import java.util.Map;


public class MeteoStation implements Meteo {
    private Locker locker;
    private MeteoData data = new MeteoData();

    public MeteoStation(Locker locker) {
        this.locker = locker;
        this.locker.addMutex("meteo", "meteo");
    }

    public MeteoData getData() {
        return data;
    }

    public void setMeteoData(int temp, int hum, int pres, int gas) {
        locker.lockModule("meteo", "meteo");
        data.temp = temp;
        data.hum = hum;
        data.pres = pres;
        data.gas = gas;
        locker.unlockModule("meteo", "meteo");
    }
}
