#ifndef LCD_I2C
#define LCD_I2C

#include <entities.h>
#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

class LCD_16x2: public LiquidCrystal_I2C, public HMI {
    private:
        uint8_t lcd_Addr;
        uint8_t lcd_cols;
        uint8_t lcd_rows;
    public:
        LCD_16x2(uint8_t id, String reference, uint8_t lcd_Addr, uint8_t lcd_cols, uint8_t lcd_rows): 
        LiquidCrystal_I2C(lcd_Addr, lcd_cols, lcd_rows), HMI(id, reference){};
        void showVariables(String variable_1, double measure_1, String variable_2, double measure_2);   
        void showAlert();
};

void LCD_16x2::showVariables(String variable_1, double measure_1, String variable_2, double measure_2){
    this->clear();
    this->setCursor(0,0);
    this->print(variable_1);
    this->print(" ");
    this->print(measure_1);
    this->setCursor(0,1);
    this->print(variable_2);
    this->print(" ");
    this->print(measure_2);
}

void LCD_16x2::showAlert(){
    this->clear();
    this->setCursor(0,0);
    this->print("    Alert !!!   ");
    this->setCursor(0,1);
    this->print("Check Vibrations");
}

#endif