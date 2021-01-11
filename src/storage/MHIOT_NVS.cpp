#include "MHIOT_NVS.h"

using namespace myHomeIoT::Storage;

MHIOT_NVS::MHIOT_NVS() = default;

MHIOT_NVS::~MHIOT_NVS() = default;

bool MHIOT_NVS::setup()
{
    nvs_flash_init();

    nvs_handle handle;
    esp_err_t err = nvs_open("led", NVS_READWRITE, &handle);
    switch (err)
    {
        case ESP_OK:
            Serial.println("NVS_OPEN_OK for led.");
            break;

        case ESP_ERR_NVS_NOT_FOUND:
            Serial.println("NVS_OPEN_ERR for led.");
            Serial.println("NVS namespace led not found.");
            return false;
            break;
        
        default:
            return false;
            break;
    }

    uint8_t white{0};
    err = nvs_get_u8(handle, "white", &white);
    switch (err)
    {
        case ESP_OK:
            Serial.println("NVS_READ_OK for white.");
            break;

        case ESP_ERR_NVS_NOT_FOUND:
            Serial.println("NVS_READ_ERR for white.");
            Serial.println("NVS not found.");
            break;
        
        default:
            break;
    }

    uint8_t red{0};
    err = nvs_get_u8(handle, "red", &red);
    switch (err)
    {
        case ESP_OK:
            Serial.println("NVS_READ_OK for red.");
            break;

        case ESP_ERR_NVS_NOT_FOUND:
            Serial.println("NVS_READ_ERR for red.");
            Serial.println("NVS not found.");
            break;
        
        default:
            break;
    }

    uint8_t green{0};
    err = nvs_get_u8(handle, "green", &green);
    switch (err)
    {
        case ESP_OK:
            Serial.println("NVS_READ_OK for green.");
            break;

        case ESP_ERR_NVS_NOT_FOUND:
            Serial.println("NVS_READ_ERR for green.");
            Serial.println("NVS not found.");
            break;
        
        default:
            break;
    }

    uint8_t blue{0};
    err = nvs_get_u8(handle, "blue", &blue);
    switch (err)
    {
        case ESP_OK:
            Serial.println("NVS_READ_OK for blue.");
            break;

        case ESP_ERR_NVS_NOT_FOUND:
            Serial.println("NVS_READ_ERR for blue.");
            Serial.println("NVS not found.");
            break;
        
        default:
            break;
    }

    myHomeIoT::LED::MHIOT_Led::getInstance()->setWhite(white);
    myHomeIoT::LED::MHIOT_Led::getInstance()->setRed(red);
    myHomeIoT::LED::MHIOT_Led::getInstance()->setGreen(green);
    myHomeIoT::LED::MHIOT_Led::getInstance()->setBlue(blue);

    return true;
}

void MHIOT_NVS::loop()
{

}

bool MHIOT_NVS::set(const char *key, uint8_t value)
{
    nvs_flash_init();

    nvs_handle handle;
    esp_err_t err = nvs_open("led", NVS_READWRITE, &handle);
    switch (err)
    {
        case ESP_OK:
            Serial.println("NVS_OPEN_OK for led.");
            break;

        case ESP_ERR_NVS_NOT_FOUND:
            Serial.println("NVS_OPEN_ERR for led.");
            Serial.println("NVS namespace led not found.");
            return false;
            break;
        
        default:
            return false;
            break;
    }

    err = nvs_set_u8(handle, key, value);
    switch (err)
    {
        case ESP_OK:
            Serial.print(F("NVS_WRITE_OK for "));
            Serial.print(key);
            Serial.println(F("."));
            break;

        case ESP_ERR_NVS_NOT_FOUND:
            Serial.println(F("NVS_WRITE_ERR for "));
            Serial.print(key);
            Serial.println(F("."));
            Serial.println(F("NVS not found."));
            return false;
            break;
        
        default:
            return false;
            break;
    }

    return true;
}
