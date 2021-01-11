#include "MHIOT_Config.h"

using namespace myHomeIoT::Config;

bool MHIOT_Config::instanceFlag = false;
MHIOT_Config* MHIOT_Config::m_pInstance = NULL;

MHIOT_Config::MHIOT_Config()
{
}

MHIOT_Config* MHIOT_Config::getInstance()
{
    if (!instanceFlag)
    {
        m_pInstance = new MHIOT_Config();
        instanceFlag = true;
    }

    return m_pInstance;
}

bool MHIOT_Config::getWiFiConfigured()
{
    return this->wiFiConfigured;
}

void MHIOT_Config::setWiFiConfigured(bool bit)
{
    this->wiFiConfigured = bit;
}

bool MHIOT_Config::getWebApiEnabled()
{
    return this->webApiEnabled;
}

void MHIOT_Config::setWebApiEnabled(bool bit)
{
    this->webApiEnabled = bit;
}

bool MHIOT_Config::getMqttEnabled()
{
    return this->mqttEnabled;
}

void MHIOT_Config::setMqttEnabled(bool bit)
{
    this->mqttEnabled = bit;
}
