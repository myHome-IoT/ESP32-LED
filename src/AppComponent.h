#ifndef MHIOT_APPCOMPONENT_H
#define MHIOT_APPCOMPONENT_H

namespace myHomeIoT
{
    class AppComponent
    {
    public:
        virtual bool setup() = 0;
        virtual void loop() = 0;
    };
}

#endif
