#include <Arduino.h>
#include <BMP180T.h>
#include <POT_PRESSURE.h>
#include <VIBSENSOR.h>

BMP180 temperature_sensor = BMP180(1, "BMP180", "Temperature");
pressureSensor pressure_sensor = pressureSensor(2, "Potentiometer", "Pressure");
vibrationsSensor vibrations_sensor = vibrationsSensor(3, "Potentiometer", "Vibrations");

unsigned long temp=millis();
double Temperature=0;
double Pressure=0;
double Vibrations=0;

void setup()
{
    Serial.begin(9600);
    while (!Serial); // Wait until monitor serial begins
    temperature_sensor.startSensor();
}

void loop()
{
    if ((millis()-temp)>=2500){
        Serial.println(" ");    
        Serial.print("Temperature: ");
        Serial.print(temperature_sensor.getMeasure());
        Serial.println(" Celcius");
        Serial.print("Pressure: ");
        Serial.print(pressure_sensor.getMeasure());
        Serial.println("Pa");
        Serial.print("Vibrations: ");
        Serial.print(vibrations_sensor.getMeasure());
        Serial.println("m/s2");
        
        temp = millis();
    }
}