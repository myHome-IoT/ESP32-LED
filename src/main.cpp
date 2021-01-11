/**
 * Author: Jonas Claes <jonasclaes2001@outlook.com>
 * Description: ESP32 LED controller.
 */

#include "App.h"

myHomeIoT::App app;

void setup()
{
    if (!app.setup())
    {
        ESP.restart();
    }
}

void loop()
{
    app.loop();
}