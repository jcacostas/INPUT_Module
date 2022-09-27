#ifndef VIBSENSOR
#define VIBSENSOR

#include <entities.h>
#include <Arduino.h>

class vibrationsSensor: public Sensor {
    public:
        vibrationsSensor(uint8_t id, String reference, String variable): Sensor(id, reference, variable){};
        double getMeasure();        
};

double vibrationsSensor::getMeasure(){
    measure=map(analogRead(1),0,1023,0,10);// vibrations intensity in m/s2
    return measure;
} 

#endif