#include "MHIOT_WebServer.h"

using namespace myHomeIoT::Web;

MHIOT_WebServer::MHIOT_WebServer() = default;

MHIOT_WebServer::~MHIOT_WebServer() = default;

bool MHIOT_WebServer::setup()
{
    server.on("/", HTTP_POST, [&](AsyncWebServerRequest *request) {
        int headers = request->headers();
        int i;
        for(i=0;i<headers;i++){
            AsyncWebHeader* h = request->getHeader(i);
            Serial.printf("HEADER[%s]: %s\n", h->name().c_str(), h->value().c_str());
        }

        if (request->hasParam("w", true))
        {
            uint8_t w = request->getParam("w", true)->value().toInt();
            myHomeIoT::LED::MHIOT_Led::getInstance()->setWhite(w);
            myHomeIoT::Storage::MHIOT_NVS::set("white", w);
        }

        if (request->hasParam("r", true))
        {
            uint8_t r = request->getParam("r", true)->value().toInt();
            myHomeIoT::LED::MHIOT_Led::getInstance()->setRed(r);
            myHomeIoT::Storage::MHIOT_NVS::set("red", r);
        }

        if (request->hasParam("g", true))
        {
            uint8_t g = request->getParam("g", true)->value().toInt();
            myHomeIoT::LED::MHIOT_Led::getInstance()->setGreen(g);
            myHomeIoT::Storage::MHIOT_NVS::set("green", g);
        }

        if (request->hasParam("b", true))
        {
            uint8_t b = request->getParam("b", true)->value().toInt();
            myHomeIoT::LED::MHIOT_Led::getInstance()->setBlue(b);
            myHomeIoT::Storage::MHIOT_NVS::set("blue", b);
        }


        request->send(200);
    });

    server.begin();

    return true;
}

void MHIOT_WebServer::loop()
{

}