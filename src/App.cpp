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

    if (!wifi.setup()) {
        Serial.println(F("Could not setup WiFi."));
        return false;
    } else {
        Serial.println(F("Setup WiFi."));
    }

    if (!webServer.setup()) {
        Serial.println(F("Could not setup webserver."));
        return false;
    } else {
        Serial.println(F("Setup webserver."));
    }

    ArduinoOTA.begin();

    Serial.println(F("Initialized."));

    return true;
}

void App::loop()
{
    ArduinoOTA.handle();
    ledcWrite(channelWhite, myHomeIoT::LED::MHIOT_Led::getInstance()->getWhite());
    ledcWrite(channelRed, myHomeIoT::LED::MHIOT_Led::getInstance()->getRed());
    ledcWrite(channelGreen, myHomeIoT::LED::MHIOT_Led::getInstance()->getGreen());
    ledcWrite(channelBlue, myHomeIoT::LED::MHIOT_Led::getInstance()->getBlue());
}
