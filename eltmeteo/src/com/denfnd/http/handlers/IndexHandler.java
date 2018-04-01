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

package com.denfnd.http.handlers;


import com.denfnd.Path;
import com.denfnd.http.PageParser;
import com.denfnd.modules.meteo.Meteo;
import com.denfnd.modules.meteo.MeteoData;
import com.denfnd.utils.Configurable;
import com.denfnd.utils.Logger;
import com.sun.net.httpserver.HttpExchange;
import com.sun.net.httpserver.HttpHandler;
import java.io.BufferedOutputStream;
import java.io.ByteArrayInputStream;
import java.io.OutputStream;


public class IndexHandler implements HttpHandler {
    private Logger log;
    private Meteo meteo;

    public IndexHandler(Logger log, Meteo meteo) {
        this.log = log;
        this.meteo = meteo;
    }

    @Override
    public void handle(HttpExchange exchange) {
        String page;
        Path path = Path.getInstance();
        PageParser parser = new PageParser();

        try {
            parser.loadTemplate(path.get("index"));
        }
        catch (Exception e) {
            log.error("Failed to load template: index.html", "INDEX_HANDLER");
            try {
                page = "<h1>403<br>Forbidden</h1>";
                exchange.sendResponseHeaders(403, page.length());
                OutputStream os = exchange.getResponseBody();
                os.write(page.getBytes());
                os.close();
            }
            catch (Exception err) {
                log.error("Failed to send answer: " + err.getMessage(), "INDEX_HANDLER");
                return;
            }
            return;
        }

        MeteoData data = meteo.getData();
        parser.setValue("temp", String.valueOf(data.temp));
        parser.setValue("hum", String.valueOf(data.hum));
        parser.setValue("pres", String.valueOf(data.pres));
        parser.setValue("gas", String.valueOf(data.gas));


        page = parser.buildPage();
        try {
            exchange.sendResponseHeaders(200, 0);
            try (BufferedOutputStream out = new BufferedOutputStream(exchange.getResponseBody())) {
                try (ByteArrayInputStream bis = new ByteArrayInputStream(page.getBytes())) {
                    int count;
                    byte [] buffer = new byte[4096];
                    while ((count = bis.read(buffer)) != -1) {
                        out.write(buffer, 0, count);
                    }
                }
            }
        }
        catch (Exception e) {
            log.error("Failed to send answer: " + e.getMessage(), "INDEX_HANDLER");
        }
    }
}
