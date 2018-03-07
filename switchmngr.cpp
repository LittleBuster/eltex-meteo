#include "switchmngr.h"
#include "switchsrv.h"
#include "wifimngr.h"
#include "meteo.h"


void SwitchMngrSetup(void)
{
    WifiMngrSetup();
    SwitchServerSetup();
    MeteoSetup();
}

void SwitchMngrLoop(void)
{
    SwitchServerLoop();
    MeteoLoop();
}