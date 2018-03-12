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

#include "pages.h"


void PagesIndexBuild(int temp, int hum, int pres, int gas, String &page)
{
    page = "<!DOCTYPE html> \
            <head> \
                <meta charset=\"utf-8\"> \
                <link rel=\"stylesheet\" type=\"text/css\" href=\"/style.css\" > \
                <meta name=\"viewport\" content=\"width=device-width, initial-scale=1\" /> \
            </head> \
             <html> \
                <body> \
                    <center> \
                        <h1>Fast Path Meteo</h1> \
                        <h2>Temperature: <b>" + String(temp) + "°</b></h2> \
                        <h2>Humidity: <b>" + String(hum) + "%</b></h2> \
                        <h2>Pressure: <b>" + String(pres) + "mm</b></h2> \
                        <h2>Gasses: <b>" + String(gas) + "%</b></h2> \
                        <br> \
                        <a><font size=\"1\" color=\"white\">Denisov Foundation Ltd. © 2018</font></a> \
                    </center> \
                </body> \
            </html>";
}

void PagesNotFoundBuild(String &page)
{
    page = "<!DOCTYPE html> \
            <head> \
                <meta charset=\"utf-8\"> \
                <link rel=\"stylesheet\" type=\"text/css\" href=\"/style.css\" > \
                <meta name=\"viewport\" content=\"width=device-width, initial-scale=1\" /> \
            </head> \
             <html> \
                <body> \
                    <center> \
                        <h1>404 Not Found</h1> \
                    </center> \
                </body> \
            </html>";
}

void PagesStyleBuild(String &page)
{
    page = "body { \
                margin: 0; \
                background: #151719; \
            } \
            h1 { \
                text-align: center; \
                position: relative; \
                color: #fff; \
                margin: 0 -30px 30px -30px; \
                padding: 10px 0; \
                text-shadow: 0 1px rgba(0,0,0,.8); \
                background: #5c5c5c; \
                background-image: -moz-linear-gradient(rgba(255,255,255,.3), rgba(255,255,255,0)); \
                background-image: -webkit-linear-gradient(rgba(255,255,255,.3), rgba(255,255,255,0)); \
                background-image: -o-linear-gradient(rgba(255,255,255,.3), rgba(255,255,255,0)); \
                background-image: -ms-linear-gradient(rgba(255,255,255,.3), rgba(255,255,255,0)); \
                background-image:  linear-gradient(rgba(255,255,255,.3), rgba(255,255,255,0)); \
                -moz-box-shadow: 0 2px 0 rgba(0,0,0,.3); \
                -webkit-box-shadow: 0 2px 0 rgba(0,0,0,.3); \
                box-shadow: 0 2px 0 rgba(0,0,0,.3); \
            } \
            h1:before, h1:after { \
                position: absolute; \
                border-style: solid; \
                border-color: transparent; \
                bottom: -10px; \
            } \
            h1:before { \
               border-width: 0 10px 10px 0; \
               border-right-color: #222; \
               left: 0; \
            } \
            h1:after { \
                border-width: 0 0 10px 10px; \
                border-left-color: #222; \
                right: 0; \
            } \
            h2 { \
                font-size: 25px; \
                line-height: 40px; \
                margin: 1em 0 .6em 0; \
                font-weight: normal; \
                color: white; \
                font-family: 'Hammersmith One', sans-serif; \
                text-shadow: 0 -1px 0 rgba(0,0,0,0.4); \
                position: relative; \
                color: #6Cf; \
            }";
}