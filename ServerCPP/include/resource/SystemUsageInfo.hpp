#pragma once

#include "resource/CPUUsageInfo.hpp"
#include "resource/NetworkUsageInfo.hpp"
#include "resource/MemoryUsageInfo.hpp"

class SystemUsageInfo {
public:
    explicit SystemUsageInfo();
    virtual ~SystemUsageInfo();

public:
    // setter
    void setCPUInfo(const CPUUsageInfo& usageInfo);
    void setMemoryInfo(const MemoryUsageInfo& usageInfo);
    void setNetworkInfo(const NetworkUsageInfo& usageInfo);

    // getter
    const CPUUsageInfo&     getCPUInfo();
    const MemoryUsageInfo&  getMemoryInfo();
    const NetworkUsageInfo& getNetworkInfo();

private:
    CPUUsageInfo cpuUsageInfo;
    MemoryUsageInfo memoryUsageInfo;
    NetworkUsageInfo networkUsageInfo;
};