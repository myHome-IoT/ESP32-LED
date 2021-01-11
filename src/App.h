#ifndef MHIOT_APP_H
#define MHIOT_APP_H

#include <Arduino.h>
#include <stdint.h>
#include <ArduinoOTA.h>
#include "AppComponent.h"
#include "storage/MHIOT_NVS.h"
#include "wireless/MHIOT_WiFi.h"
#include "web/MHIOT_WebServer.h"
#include "led/MHIOT_Led.h"

namespace myHomeIoT
{
    class App: public myHomeIoT::AppComponent
    {
    private:
        myHomeIoT::Storage::MHIOT_NVS nvsStorage;
        myHomeIoT::Wireless::MHIOT_WiFi wifi;
        myHomeIoT::Web::MHIOT_WebServer webServer;
        const uint16_t pwmFrequency{5000};
        const uint8_t pwmResolution{8};
        const uint8_t pinWhite{12};
        const uint8_t pinBlue{14};
        const uint8_t pinRed{26};
        const uint8_t pinGreen{27};
        const uint8_t channelWhite{0};
        const uint8_t channelRed{1};
        const uint8_t channelGreen{2};
        const uint8_t channelBlue{3};
    public:
        App();
        ~App();

        bool setup();
        void loop();
    };
}

#endif
