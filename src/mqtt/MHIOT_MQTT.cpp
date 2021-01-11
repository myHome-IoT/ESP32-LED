#include "MHIOT_MQTT.h"

using namespace myHomeIoT::MQTT;

MHIOT_MQTT::MHIOT_MQTT() = default;

MHIOT_MQTT::~MHIOT_MQTT() = default;

bool MHIOT_MQTT::setup()
{
    // mqttClient.setServer();
    // mqttClient.setCallback();

    return true;
}

void MHIOT_MQTT::loop()
{
    // while (!mqttClient.connected())
    // {
    //     Serial.println(F("Attempting MQTT connection..."));

    //     uint32_t chipId{0};
    //     for(int i=0; i<17; i=i+8) {
    //         chipId |= ((ESP.getEfuseMac() >> (40 - i)) & 0xff) << i;
    //     }

    //     if (mqttClient.connect(("ESP32-" + String(chipId)).c_str(), user, password)) {
    //         Serial.println("Connected to " + String(server));
    //     } else {
    //         Serial.print("Failed, rc=");
    //         Serial.println(mqttClient.state());

    //         delay(2000);
    //     }
    // }

    // mqttClient.loop();
}
