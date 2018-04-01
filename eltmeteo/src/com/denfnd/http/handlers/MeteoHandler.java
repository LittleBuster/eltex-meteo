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


import com.denfnd.http.ParamsDecoder;
import com.denfnd.modules.meteo.Meteo;
import com.denfnd.modules.meteo.MeteoData;
import com.denfnd.utils.Logger;
import com.sun.net.httpserver.HttpExchange;
import com.sun.net.httpserver.HttpHandler;
import java.io.OutputStream;


public class MeteoHandler implements HttpHandler {
    private Logger log;
    private Meteo meteo;

    public MeteoHandler(Logger log, Meteo meteo) {
        this.log = log;
        this.meteo = meteo;
    }

    @Override
    public void handle(HttpExchange exchange) {
        String page = "{\"result\": false}";
        ParamsDecoder ps = new ParamsDecoder();

        try {
            ps.split(exchange.getRequestURI().getQuery());
        }
        catch (Exception e) {
            log.error("Failed to decoding params", "METEO_HANDLER");
            try {
                exchange.sendResponseHeaders(403, page.length());
                OutputStream os = exchange.getResponseBody();
                os.write(page.getBytes());
                os.close();
            }
            catch (Exception err) {
                log.error("Failed to send answer: " + err.getMessage(), "METEO_HANDLER");
            }
            return;
        }

        if (ps.getParam("act").equals("add_meteo") && ps.getCount() == 5) {
            meteo.setMeteoData(Integer.valueOf(ps.getParam("temp")),
                               Integer.valueOf(ps.getParam("hum")),
                               Integer.valueOf(ps.getParam("pres")),
                               Integer.valueOf(ps.getParam("gas")));

            page = "{\"result\": true}";
        }
        else if (ps.getParam("act").equals("get_meteo")) {
            MeteoData data = meteo.getData();

            page = "{\"result\": true, \"temp\": " + data.temp + ", \"hum\": " + data.hum + ", \"pres\": " + data.pres +
                    ", \"gas\": " + data.gas + "}";
        }

        try {
            exchange.sendResponseHeaders(200, page.length());
            OutputStream os = exchange.getResponseBody();
            os.write(page.getBytes());
            os.close();
        }
        catch (Exception e) {
            log.error("Failed to send answer: " + e.getMessage(), "METEO_HANDLER");
        }
    }
}