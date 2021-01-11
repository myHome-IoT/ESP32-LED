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
            const char *ssid = "Residentie Wijckmans";
            const char *password = "wIJCK965061";
        public:
            MHIOT_WiFi();
            ~MHIOT_WiFi();

            bool setup();
            void loop();
        };
    }
}

#endif
