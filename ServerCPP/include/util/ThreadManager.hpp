#pragma once

#include "util/Thread.hpp"

#include <vector>
#include <memory>

class ThreadManager {
public:
    explicit ThreadManager();
    virtual ~ThreadManager();

public:
    void start();
    void join();

    void pushThread(Thread& thread);

private:
    std::vector<Thread*> threadList;
};