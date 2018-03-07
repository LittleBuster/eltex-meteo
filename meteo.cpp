#include "meteo.h"
#include "configs.h"

#include <Arduino.h>


unsigned oldTime;
unsigned meteoCounter;


void MeteoSetup(void)
{
    oldTime = 0;
    meteoCounter = 0;
    isFirst = true;

    //First read call
}

void MeteoLoop(void)
{
    unsigned nowTime = millis() / 1000;

    if (isFirst || meteoCounter == CFG_METEO_DELAY) {
        meteoCounter = 0;
        //Regular read call 
    }

    if (nowTime != oldTime) {
        oldTime = nowTime;
        meteoCounter++;
    }
}