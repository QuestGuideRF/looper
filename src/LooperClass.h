#pragma once
#include <inttypes.h>
#include "./nodes/LoopTask.h"
#include "./platform.h"
#include "./utils/hash.h"
#include "./utils/list.h"
#include "./utils/macro.h"
#include "./utils/stack.h"
class LoopTimer;
class LoopThread;
class LooperClass {
    LP_MAKE_CALLBACK(LooperCallback, void, hash_t);
   public:
    void loop(bool main = true);
    void reset();
    uint16_t length();
    uint32_t nextTimerLeft();
    void delay(uint32_t ms);
    void add(LoopTask* task);
    void remove(LoopTask* task);
    void removeThis();
    void removeAll();
    LoopTask* operator[](hash_t id);
    LoopTask* operator[](const char* id);
    LoopTask* getTask(hash_t id);
    LoopTask* getTask(const char* id);
    LoopTimer* getTimer(hash_t id);
    LoopTimer* getTimer(const char* id);
    LoopThread* getThread(hash_t id);
    LoopThread* getThread(const char* id);
    LoopTask* thisTask();
    LoopTimer* thisTimer();
    LoopThread* thisThread();
    template <typename T>
    T* thisTaskAs() {
        return static_cast<T*>(_thisTask);
    }
    tState thisState();
    bool thisSetup();
    bool thisExit();
    bool thisLoop();
    bool thisEvent();
    void* eventData();
    LoopTask* eventSource();
    bool eventBroadcast();
    void sendEvent(hash_t id, void* data = nullptr);
    void sendEvent(const char* id, void* data = nullptr);
    bool pushEvent(hash_t id, void* data = nullptr);
    bool pushEvent(const char* id, void* data = nullptr);
    void onEvent(LooperCallback callback);
    void _removeNow(LoopTask* task);
   private:
    struct EventData {
        hash_t id;
        void* data;
    };
#if LOOPER_USE_EVENTS
#if LOOPER_QUEUE_SIZE
    looper::Stack<EventData, LOOPER_QUEUE_SIZE> _events;
#endif
    LooperCallback _event_cb = nullptr;
    LoopTask* _thisSource = nullptr;
    void* _thisData = nullptr;
    bool _thisBroad = false;
#endif
    looper::List<LoopTask> _tasks;
    LoopTask* _thisTask = nullptr;
    tState _thisState = tState::Loop;
    void _sendEvent(EventData& evt);
    void _execState(tState state);
};
extern LooperClass LP;
extern LooperClass& Looper;