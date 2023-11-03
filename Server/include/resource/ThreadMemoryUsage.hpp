#pragma once

#include "util/Result.hpp"
#include "util/ReturnedThread.hpp"
#include "resource/MemoryUsageInfo.hpp"

class ThreadMemoryUsage : public ReturnedThread<MemoryUsageInfo> {
public:
    explicit ThreadMemoryUsage();
    virtual ~ThreadMemoryUsage();

protected:
    virtual void run(MemoryUsageInfo* usageInfo, Result* result) override;
};