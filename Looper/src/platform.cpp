#include "./platform.h"
#include <Arduino.h>
namespace looper {
uint32_t millis() {
    return ::millis();
}
void yield() {
    delay(0);
}
}