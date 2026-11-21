#pragma once
#include "../utils/macro.h"
template <typename T>
class TaskCallbackData {
    LP_MAKE_CALLBACK(DataCallback, void, T*);
   public:
    TaskCallbackData(T* data, DataCallback callback) : _data(data), _cb(callback) {}
    void setData(T* data) {
        _data = data;
    }
    T* getData() {
        return _data;
    }
    void exec() {
        if (_cb) _cb(_data);
    }
   private:
    T* _data;
    DataCallback _cb;
};