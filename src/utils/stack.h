#pragma once
#include <inttypes.h>
#include <stddef.h>
namespace looper {
template <typename T, uint8_t capacity>
class Stack {
   public:
    bool push(T val) {
        if (_len >= capacity) return false;
        _stack[_len++] = val;
        return true;
    }
    T& pop() {
        return _stack[--_len];
    }
    inline uint8_t length() {
        return _len;
    }
   private:
    T _stack[capacity] = {};
    uint8_t _len = 0;
};
}