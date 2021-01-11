#ifndef MHIOT_NVS_H
#define MHIOT_NVS_H

#include "AppComponent.h"
#include <nvs.h>
#include <nvs_flash.h>
#include <stdint.h>
#include <HardwareSerial.h>
#include <Esp.h>
#include "led/MHIOT_Led.h"
#include "config/MHIOT_Config.h"

namespace myHomeIoT
{
    namespace Storage
    {
        class MHIOT_NVS: public AppComponent
        {
            public:
                MHIOT_NVS();
                ~MHIOT_NVS();

                bool setup();
                void loop();
                static bool set(const char *kvName, const char *key, uint8_t value);
                static bool saveConfig();
        };
    }
}

#endif
