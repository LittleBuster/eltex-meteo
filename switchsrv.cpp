#include "switchsrv.h"
#include "configs.h"
#include "pages.h"

#include <Arduino.h>
#include <ESP8266WebServer.h>


ESP8266WebServer server(CFG_SERVER_PORT);


static void IndexHandler(void)
{
    String page;

    PagesIndexBuild(page);

    server.send(200, "text/html", page);
}

static void NotFoundHandler(void)
{
    String page;

    PagesNotFoundBuild(page);

    server.send(200, "text/html", page);
}


void SwitchServerSetup(void)
{
    server.on(CFG_INDEX_HANDLER, IndexHandler);
    server.onNotFound(NotFoundHandler);
    server.begin();
}

void SwitchServerLoop(void)
{
    server.handleClient();
}