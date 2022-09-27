#include <Arduino.h>
#include <BMP180T.h>
#include <POT_PRESSURE.h>
#include <VIBSENSOR.h>
#include <LCD_I2C.h>

String var1="Temperature";
String var2="Pressure";
String var3="Vibrations";

BMP180 temperature_sensor = BMP180(1, "BMP180", var1);
pressureSensor pressure_sensor = pressureSensor(2, "Potentiometer", var2);
vibrationsSensor vibrations_sensor = vibrationsSensor(3, "Potentiometer", var3);
LCD_16x2 LCD_screen = LCD_16x2(4, "Screen", 0x27, 16, 2);

unsigned long temp=millis();
double Temperature=0;
double Pressure=0;
double Vibrations=0;

void setup()
{
    Serial.begin(9600);
    while (!Serial); // Wait until monitor serial begins
    temperature_sensor.startSensor();
    LCD_screen.init();
    LCD_screen.backlight();
    LCD_screen.clear();
}

void loop()
{
    if ((millis()-temp)>=2500)
    {
        if (vibrations_sensor.getMeasure()>8){
            LCD_screen.showAlert();
        } else {
            Serial.println(" ");    
            Serial.print(var1);
            Serial.print(temperature_sensor.getMeasure()); // Temperature in Celcius
            Serial.println(" Celcius");
            Serial.print(var2);
            Serial.print(pressure_sensor.getMeasure()); // Pressure in Pa
            Serial.println("Pa");
            Serial.print(var3);
            Serial.print(vibrations_sensor.getMeasure()); // Vibrations intensity in m/s2
            Serial.println("m/s2");
            LCD_screen.showVariables(var1, temperature_sensor.getMeasure(), var2, pressure_sensor.getMeasure());
        }
    temp=millis();
    }
}