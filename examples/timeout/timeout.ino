#include <Arduino.h>
#include <Looper.h>
LP_TIMER(1000, []() {
    Serial.println("timer stop!");
    LP.thisTimer()->stop();
});
void setup() {
    Serial.begin(115200);
}
void loop() {
    LP.loop();
}