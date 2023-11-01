#pragma once

#include "util/Result.hpp"
#include "util/ReturnedThread.hpp"
#include "resource/CPUUsageInfo.hpp"

class ThreadCPUUsage : public ReturnedThread<CPUUsageInfo> {
public:
    explicit ThreadCPUUsage();
    virtual ~ThreadCPUUsage();

protected:
    virtual void run(CPUUsageInfo* usageInfo, Result* result) override;
};