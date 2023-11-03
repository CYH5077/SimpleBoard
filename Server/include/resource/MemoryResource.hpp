#pragma once

#include "resource/MemoryUsageInfo.hpp"
#include "util/Result.hpp"

#include <sys/sysinfo.h>

class MemoryResource {
public:
    explicit MemoryResource();
    virtual ~MemoryResource();

public:
    bool readMemoryUsageInfo(MemoryUsageInfo* memoryUsageInfo, Result* result);

private:
    bool readMemoryInfo(MemoryUsageInfo* memoryUsageInfo, Result* result);

    double calcTotalMemory(struct sysinfo& sysinfo);
    double calcUsageMemory(struct sysinfo& sysinfo);
    double calcTotalVirtualMemory(struct sysinfo& sysinfo);
    double calcUsageVirtualMemory(struct sysinfo& sysinfo);
    
};