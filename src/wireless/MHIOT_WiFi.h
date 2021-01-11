#ifndef MHIOT_WIFI_H
#define MHIOT_WIFI_H

#include "AppComponent.h"
#include <WiFi.h>

namespace myHomeIoT
{
    namespace Wireless
    {
        class MHIOT_WiFi: public myHomeIoT::AppComponent
        {
        private:
            const char *ssid = "SSID";
            const char *password = "PWD";
        public:
            MHIOT_WiFi();
            ~MHIOT_WiFi();

            bool setup();
            void loop();
        };
    }
}

#endif
