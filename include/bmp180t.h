#ifndef BMP180T
#define BMP180T

#include <entities.h>
#include <Arduino.h>
#include <SFE_BMP180.h>

class BMP180: public SFE_BMP180, public Sensor {
    public:
        BMP180(uint8_t id, String reference, String variable): SFE_BMP180(), Sensor(id, reference, variable){};
        double getMeasure();
        void startSensor();        
};

double BMP180::getMeasure(){
    unsigned long status = this->startTemperature();//Inicio de lectura de temperatura
    unsigned long temp=millis();
    while ((millis()-temp)<status)
    {
        // Espera a que se tome la medida
    }
    status = this->getTemperature(measure); //Obtener la temperatura
    return measure;
} 

void BMP180::startSensor(){
    if (this->begin()){
        Serial.println("BMP180 iniciado correctamente");
    }
    else{
        Serial.println("Error al iniciar el BMP180");
        while (1); // No dejar continuar
    }
}

#endif