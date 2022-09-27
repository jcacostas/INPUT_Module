#ifndef ENTITIES
#define ENTITIES

#include <stdint.h>
#include <Arduino.h>

class Device {
    private:
        uint8_t id;
        String reference;
    public:
        Device(uint8_t,String);
        uint8_t getId();
        String getReference();
};
Device::Device(uint8_t id, String reference){
    this->id = id;
    this->reference = reference;
};
uint8_t Device::getId(){
    return this->id;
};
String Device::getReference(){
    return this->reference;
};

class Sensor : public Device {
    private:
        String variable;
    protected:
        double measure;
    public:
        Sensor(uint8_t id, String reference, String variable): Device(id, reference){
            this->variable = variable;
        };
        virtual double getMeasure()=0;
        String getVariable();
};

String Sensor::getVariable(){
    return this->variable;
};

#endif