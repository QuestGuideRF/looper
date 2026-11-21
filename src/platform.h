#pragma once
#include <inttypes.h>
#ifndef LOOPER_QUEUE_SIZE
#define LOOPER_QUEUE_SIZE 3
#endif
#ifndef LOOPER_USE_ID
#define LOOPER_USE_ID true
#endif
#ifndef LOOPER_USE_EVENTS
#define LOOPER_USE_EVENTS true
#endif
namespace looper {
uint32_t millis();
void yield();
}