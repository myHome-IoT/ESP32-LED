#include "App.h"

using namespace myHomeIoT;

App::App() = default;

App::~App() = default;

bool App::setup()
{
    Serial.begin(115200);
    Serial.println();
    Serial.println(F("myHome IoT - ESP32 LED controller"));
    Serial.println(F("Initializing..."));

    // Setup LED channels
    ledcSetup(channelWhite, pwmFrequency, pwmResolution);
    ledcAttachPin(pinWhite, channelWhite);
    ledcSetup(channelRed, pwmFrequency, pwmResolution);
    ledcAttachPin(pinRed, channelRed);
    ledcSetup(channelGreen, pwmFrequency, pwmResolution);
    ledcAttachPin(pinGreen, channelGreen);
    ledcSetup(channelBlue, pwmFrequency, pwmResolution);
    ledcAttachPin(pinBlue, channelBlue);

    if (!nvsStorage.setup()) {
        Serial.println(F("Could not setup NVS."));
        return false;
    } else {
        Serial.println(F("Setup NVS."));
    }

    if (myHomeIoT::Config::MHIOT_Config::getInstance()->getWiFiConfigured())
    {
        if (!wifi.setup()) {
            Serial.println(F("Could not setup WiFi."));
            return false;
        } else {
            Serial.println(F("Setup WiFi."));
        }
    } else {
        uint32_t chipId{0};
        for(int i=0; i<17; i=i+8) {
            chipId |= ((ESP.getEfuseMac() >> (40 - i)) & 0xff) << i;
        }

        WiFi.softAP(("ESP32-LED@" + String(chipId)).c_str(), "123456789");
        IPAddress ip = WiFi.softAPIP();
        Serial.print(F("SoftAP IP: "));
        Serial.println(ip);
        ledcWrite(channelRed, 255);
    }

    if (!webServer.setup()) {
        Serial.println(F("Could not setup webserver."));
        return false;
    } else {
        Serial.println(F("Setup webserver."));
    }

    if (!mqttClient.setup()) {
        Serial.println(F("Could not setup MQTT client."));
        return false;
    } else {
        Serial.println(F("Setup MQTT client."));
    }

    ArduinoOTA.begin();

    Serial.println(F("Initialized."));

    return true;
}

void App::loop()
{
    ArduinoOTA.handle();

    if (Config::MHIOT_Config::getInstance()->getWiFiConfigured())
    {
        mqttClient.loop();
        ledcWrite(channelWhite, myHomeIoT::LED::MHIOT_Led::getInstance()->getWhite());
        ledcWrite(channelRed, myHomeIoT::LED::MHIOT_Led::getInstance()->getRed());
        ledcWrite(channelGreen, myHomeIoT::LED::MHIOT_Led::getInstance()->getGreen());
        ledcWrite(channelBlue, myHomeIoT::LED::MHIOT_Led::getInstance()->getBlue());
    }
}
