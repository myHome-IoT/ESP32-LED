#include "MHIOT_WiFi.h"

using namespace myHomeIoT::Wireless;

MHIOT_WiFi::MHIOT_WiFi() = default;

MHIOT_WiFi::~MHIOT_WiFi() = default;

bool MHIOT_WiFi::setup()
{
    Serial.print("Connecting to ");
    Serial.print(ssid);
    
    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, password);
    int attempts = 0;
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
        attempts++;
        
        if (attempts > 10) return false;
    }
    Serial.println();
    Serial.println("WiFi connected.");
    Serial.println("IPv4 address: " + WiFi.localIP().toString());
    Serial.println("IPv6 address: " + WiFi.localIPv6().toString());
    return true;
}

void MHIOT_WiFi::loop()
{

}