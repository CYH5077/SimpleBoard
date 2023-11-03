#pragma once

#include "util/Thread.hpp"
#include "util/Result.hpp"

#include <thread>
#include <future>
#include <memory>

template <typename RETURN_TYPE>
class ReturnedThread : public Thread {
public:
    explicit ReturnedThread() {}
    virtual ~ReturnedThread() {}


public:
    virtual void start() {
        try{
            this->thread = std::make_shared<std::thread>([&](){
                RETURN_TYPE returnValue;
                this->run(&returnValue, &this->result);
                this->setReturn(returnValue);
            });
        } catch (const std::bad_alloc& e) {
            this->result.failed(-1, e.what());
        }
    }

    virtual void join() {
        this->thread->join();
    }

protected: // interface
    virtual void run(RETURN_TYPE* returnValue, Result* result) = 0;

public: 
    // getter
    const RETURN_TYPE& getReturn() { return this->returnValue; }
    const Result&      getResult() { return this->result; }
    std::shared_ptr<std::thread> getRowContext() { return this->thread; }

    // setter
    void setReturn(RETURN_TYPE& returnValue) { this->returnValue = returnValue; }

private:
    std::shared_ptr<std::thread> thread;

    Result result;
    RETURN_TYPE returnValue;
};