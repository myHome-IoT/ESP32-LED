#ifndef MHIOT_WEBSERVER_H
#define MHIOT_WEBSERVER_H

#include "AppComponent.h"
#include <ESPAsyncWebServer.h>
#include "led/MHIOT_Led.h"
#include "storage/MHIOT_NVS.h"
#include "config/MHIOT_Config.h"

namespace myHomeIoT
{
    namespace Web
    {
        class MHIOT_WebServer: public myHomeIoT::AppComponent
        {
        protected:
            AsyncWebServer server{80};
            unsigned long currentTime{millis()};
            unsigned long previousTime{0};
            const unsigned long timeoutTime{5000};
        public:
            MHIOT_WebServer();
            ~MHIOT_WebServer();

            bool setup();
            void loop();
        };
    }
}

#endif
