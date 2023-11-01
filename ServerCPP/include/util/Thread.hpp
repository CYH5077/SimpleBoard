#pragma once

#include "util/Result.hpp"

#include <thread>
#include <memory>

class Thread {
public:
    explicit Thread() {}
    virtual ~Thread() {}

public:
    virtual void start() = 0;
    virtual void join() = 0;
};