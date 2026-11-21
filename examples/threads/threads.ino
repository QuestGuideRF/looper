#include <Arduino.h>
#include <Looper.h>
LP_THREAD({
    pinMode(LED_BUILTIN, OUTPUT);
    while (true) {
        digitalWrite(LED_BUILTIN, 1);
        LP_DELAY(500);
        digitalWrite(LED_BUILTIN, 0);
        LP_DELAY(500);
    }
});
void setup() {
    Serial.begin(115200);
}
void loop() {
    Looper.loop();
}