#include <Arduino.h>
#include <BMP180T.h>
#include <POT_PRESSURE.h>
#include <VIBSENSOR.h>
#include <LCD_I2C.h>
#include <llp.h>

String var1="Temperature";
String var2="Pressure";
String var3="Vibrations";

BMP180 temperature_sensor = BMP180(0XA6, "BMP180", var1);
pressureSensor pressure_sensor = pressureSensor(0X9C, "Potentiometer", var2);
vibrationsSensor vibrations_sensor = vibrationsSensor(0X2B, "Potentiometer", var3);
LCD_16x2 LCD_screen = LCD_16x2(0X10, "Screen", 0x27, 16, 2);

double tresholdVibrations=8;
unsigned long temp=millis();

void setup()
{
    Serial.begin(9600);
    while (!Serial); // Wait until monitor serial begins
    temperature_sensor.startSensor();
    LCD_screen.init();
    LCD_screen.backlight();
    LCD_screen.clear();
    LCD_screen.showVariables(var1, temperature_sensor.getMeasure(), var2, pressure_sensor.getMeasure());
}

void loop()
{
    if ((millis()-temp)>2500){
        if (vibrations_sensor.alertDetection(tresholdVibrations)){
            LCD_screen.showVibrationsAlert();
        } else {
            LCD_screen.showVariables(var1, temperature_sensor.getMeasure(), var2, pressure_sensor.getMeasure());
        }
        DataPack payload;
        payload.addData(
            temperature_sensor.getId(), 
            uint16_t(temperature_sensor.getMeasure())
        );
        payload.addData(
            pressure_sensor.getId(), 
            uint16_t(pressure_sensor.getMeasure())
        );
        payload.addData(
            vibrations_sensor.getId(),
            uint16_t(vibrations_sensor.alertDetection(tresholdVibrations)==1 ? 2^15 : 0)
        );
        payload.write(Serial);
        temp=millis();
    }   
}