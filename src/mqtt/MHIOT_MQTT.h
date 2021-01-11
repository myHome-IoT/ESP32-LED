#ifndef MHIOT_MQTT_H
#define MHIOT_MQTT_H

#include <WiFiClient.h>
#include <PubSubClient.h>
#include "AppComponent.h"

namespace myHomeIoT
{
    namespace MQTT
    {
        class MHIOT_MQTT: public AppComponent
        {
            private:
                const char* server = "";
                const char* user = "";
                const char* password = "";
                const char* channelId = "";
            protected:
                WiFiClient wiFiClient;
                PubSubClient mqttClient{wiFiClient};
            public:
                MHIOT_MQTT();
                ~MHIOT_MQTT();

                bool setup();
                void loop();
        };
    }
}

#endif
