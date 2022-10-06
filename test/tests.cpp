#include <unity.h>
#include <Arduino.h>
#include <BMP180T.h>
#include <POT_PRESSURE.h>
#include <VIBSENSOR.h>

void testGetId(void) {
    uint8_t Id=0;
    BMP180 temperature_sensor = BMP180(Id, "BMP180", "Temperature");
    TEST_ASSERT_TRUE(temperature_sensor.getId()==Id);
}
void testGetReference(void) {
    String reference="exampleRef";
    BMP180 temperature_sensor = BMP180(9, reference, "Temperature");
    TEST_ASSERT_TRUE(temperature_sensor.getReference()==reference);
}
void testGetVariable(void) {
    String var="Temperature";
    BMP180 temperature_sensor = BMP180(9, "BMP180", var);
    TEST_ASSERT_TRUE(temperature_sensor.getVariable()==var);
}
void testAlertVibrations(void) {
    double tresholdVibrations=8;
    vibrationsSensor vibrations_sensor = vibrationsSensor(3, "Potentiometer", "Vibrations");
    TEST_ASSERT_FALSE(vibrations_sensor.alertDetection(tresholdVibrations));
}

int main(int argc, char **argv) {
    UNITY_BEGIN();
    RUN_TEST(testGetId);
    RUN_TEST(testGetReference);
    RUN_TEST(testGetVariable);
    RUN_TEST(testAlertVibrations);
    UNITY_END();
    return 0;
}
