#ifndef POT_PRESSURE
#define POT_PRESSURE

#include <entities.h>
#include <Arduino.h>

class pressureSensor: public Sensor {
    public:
        pressureSensor(uint8_t id, String reference, String variable): Sensor(id, reference, variable){};
        double getMeasure();        
};

double pressureSensor::getMeasure(){
    measure=map(analogRead(0),0,1023,0,4000);// Pressure in Pascals
    return measure;
} 

#endif