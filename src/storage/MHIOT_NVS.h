#ifndef MHIOT_NVS_H
#define MHIOT_NVS_H

#include "AppComponent.h"
#include <nvs.h>
#include <nvs_flash.h>
#include <stdint.h>
#include <HardwareSerial.h>
#include "led/MHIOT_Led.h"

namespace myHomeIoT
{
    namespace Storage
    {
        class MHIOT_NVS: public AppComponent
        {
            private:
                
            public:
                MHIOT_NVS();
                ~MHIOT_NVS();

                bool setup();
                void loop();
                static bool set(const char *key, uint8_t value);
        };
    }
}

#endif
