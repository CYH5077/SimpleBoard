#pragma once

#include "util/Result.hpp"
#include "util/ReturnedThread.hpp"
#include "resource/NetworkUsageInfo.hpp"

class ThreadNetworkUsage : public ReturnedThread<NetworkUsageInfo> {
public:
    explicit ThreadNetworkUsage(std::string& networkInterfaceName);
    virtual ~ThreadNetworkUsage();

protected:
    virtual void run(NetworkUsageInfo* usageInfo, Result* result) override;

private:
    std::string networkInterfaceName;
};