#ifndef MHIOT_CONFIG_H
#define MHIOT_CONFIG_H

#include <stdint.h>
#include <HardwareSerial.h>

namespace myHomeIoT
{
    namespace Config
    {
        class MHIOT_Config
        {
        private:
            static bool instanceFlag;
            static MHIOT_Config *m_pInstance;
            MHIOT_Config();

            bool wiFiConfigured{false};
            bool webApiEnabled{false};
            bool mqttEnabled{false};
        public:
            ~MHIOT_Config();
            static MHIOT_Config *getInstance();

            bool getWiFiConfigured();
            void setWiFiConfigured(bool bit);
            bool getWebApiEnabled();
            void setWebApiEnabled(bool bit);
            bool getMqttEnabled();
            void setMqttEnabled(bool bit);
        };
    }
}

#endif
