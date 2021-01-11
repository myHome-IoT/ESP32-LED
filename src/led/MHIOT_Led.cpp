#include "MHIOT_Led.h"

using namespace myHomeIoT::LED;

MHIOT_Led* MHIOT_Led::m_pInstance = 0;

MHIOT_Led::MHIOT_Led()
{
    R = (255 * log10(2))/(log10(255));
    Serial.print(F("R: "));
    Serial.println(R);
} 

MHIOT_Led* MHIOT_Led::getInstance()
{
    if (!m_pInstance)
        m_pInstance = new MHIOT_Led;

    return m_pInstance;
}

uint8_t MHIOT_Led::getWhite()
{
    return this->w;
}

void MHIOT_Led::setWhite(uint8_t white) {
    this->w = ceil(pow(2, (white / R)) - 1);
    Serial.printf("R: %.3f; White: %i;\r\n", R, w);
}

uint8_t MHIOT_Led::getRed()
{
    return this->r;
}

void MHIOT_Led::setRed(uint8_t red) {
    this->r = ceil(pow(2, (red / R)) - 1);
    Serial.printf("R: %.3f; Red: %i;\r\n", R, r);
}

uint8_t MHIOT_Led::getGreen()
{
    return this->g;
}

void MHIOT_Led::setGreen(uint8_t green) {
    this->g = ceil(pow(2, (green / R)) - 1);
    Serial.printf("R: %.3f; Green: %i;\r\n", R, g);
}

uint8_t MHIOT_Led::getBlue()
{
    return this->b;
}

void MHIOT_Led::setBlue(uint8_t blue) {
    this->b = ceil(pow(2, (blue / R)) - 1);
    Serial.printf("R: %.3f; Blue: %i;\r\n", R, b);
}