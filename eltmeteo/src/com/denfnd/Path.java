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


import java.util.HashMap;
import java.util.Map;


public class Path {
    private static Path path;
    private Map<String, String> files = new HashMap<>();

    private Path() {
        files.put("log", "/var/log/eltmeteo.log");
        files.put("cfg", "/etc/eltmeteo.conf");
        files.put("index", "/root/eltmeteo/index.html");
        files.put("css", "/root/eltmeteo/style.css");
    }

    public static synchronized Path getInstance() {
        if (path == null)
            path = new Path();
        return path;
    }

    public String get(String name) {
        return files.get(name);
    }

    public void add(String name, String path) {
        files.put(name, path);
    }
}
