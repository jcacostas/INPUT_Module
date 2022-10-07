#include <Arduino.h>
#include <BMP180T.h>
#include <POT_PRESSURE.h>
#include <VIBSENSOR.h>
#include <LCD_I2C.h>

String var1="Temperature";
String var2="Pressure";
String var3="Vibrations";

BMP180 temperature_sensor = BMP180(0X01, "BMP180", var1);
pressureSensor pressure_sensor = pressureSensor(0X02, "Potentiometer", var2);
vibrationsSensor vibrations_sensor = vibrationsSensor(0X03, "Potentiometer", var3);
LCD_16x2 LCD_screen = LCD_16x2(0X04, "Screen", 0x27, 16, 2);

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
}

void loop()
{
    if ((millis()-temp)>=2500)
    {
        if (vibrations_sensor.alertDetection(tresholdVibrations)){
            LCD_screen.showVibrationsAlert();
        } else {
            LCD_screen.showVariables(var1, temperature_sensor.getMeasure(), var2, pressure_sensor.getMeasure());
        }
    temp=millis();
    }
}