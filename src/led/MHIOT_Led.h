#ifndef MHIOT_LED_H
#define MHIOT_LED_H

#include <stdint.h>
#include <HardwareSerial.h>

namespace myHomeIoT
{
    namespace LED
    {
        class MHIOT_Led
        {
        private:
            static bool instanceFlag;
            static MHIOT_Led *m_pInstance;
            MHIOT_Led();
            // MHIOT_Led(MHIOT_Led const&) {};
            // MHIOT_Led& operator=(MHIOT_Led const&){};

            float R{0};
            uint8_t w{0};
            uint8_t r{0};
            uint8_t g{0};
            uint8_t b{0};
        public:
            ~MHIOT_Led();
            static MHIOT_Led *getInstance();

            uint8_t getWhite();
            void setWhite(uint8_t white);
            uint8_t getRed();
            void setRed(uint8_t red);
            uint8_t getGreen();
            void setGreen(uint8_t green);
            uint8_t getBlue();
            void setBlue(uint8_t blue);
        };
    }
}

#endif
