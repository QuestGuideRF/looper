#pragma once
#include <inttypes.h>
#include <stddef.h>
class SimpleTimer {
   public:
    SimpleTimer(uint32_t ms = 0, bool start = true);
    void restart();
    void restart(uint32_t ms, uint32_t sec = 0, uint16_t min = 0, uint16_t hour = 0, uint16_t day = 0);
    void stop();
    void force();
    bool running();
    bool ready();
    explicit operator bool() {
        return ready();
    }
    uint32_t getPeriod();
    bool interval();
    bool timeout();
    uint32_t left();
   private:
    uint32_t _tmr = 0, _prd = 0;
};