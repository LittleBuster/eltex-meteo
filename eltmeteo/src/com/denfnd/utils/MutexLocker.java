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

package com.denfnd.utils;


import java.util.HashMap;
import java.util.Map;

public class MutexLocker implements Locker {
    private Map<String, String> meteo = new HashMap<>();

    public void addMutex(String module, String mutex) {

    }

    public boolean lockModule(String module, String mutex) {
        switch (module) {
            case "meteo":
                meteo.get(mutex);
                break;
            default:
                return false;
        }
        return true;
    }

    public boolean unlockModule(String module, String mutex) {
        switch (module) {
            case "meteo":
                meteo.get(mutex);
                break;
            default:
                return false;
        }
        return true;
    }
}
