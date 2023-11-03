#include "resource/MemoryResource.hpp"

#include <sys/sysinfo.h>

MemoryResource::MemoryResource() {

}

MemoryResource::~MemoryResource() {

}

bool MemoryResource::readMemoryUsageInfo(MemoryUsageInfo* memoryUsageInfo, Result* result) {
    if (memoryUsageInfo == nullptr ||
        result          == nullptr) {
            return false;
        }

    return this->readMemoryInfo(memoryUsageInfo, result);
}

bool MemoryResource::readMemoryInfo(MemoryUsageInfo* memoryUsageInfo, Result* result) {
    struct sysinfo sysInfo;
    if (sysinfo(&sysInfo) == -1) {
        return result->failed(-1, "sysinfo() 에서 시스템 정보를 가져오는데 실패 했습니다.");
    }

    memoryUsageInfo->setTotalMemory(this->calcTotalMemory(sysInfo));
    memoryUsageInfo->setUsageMemory(this->calcUsageMemory(sysInfo));
    memoryUsageInfo->setTotalVirtualMemory(this->calcTotalVirtualMemory(sysInfo));
    memoryUsageInfo->setUsageVirtualMemory(this->calcUsageVirtualMemory(sysInfo));

    return result->success();
}

double MemoryResource::calcTotalMemory(struct sysinfo& sysInfo) {
    return sysInfo.totalram * sysInfo.mem_unit;
}

double MemoryResource::calcUsageMemory(struct sysinfo& sysInfo) {
    double usageMemory;
    usageMemory  = sysInfo.totalram - sysInfo.freeram;
    usageMemory *= sysInfo.mem_unit;
    return usageMemory;
}

double MemoryResource::calcTotalVirtualMemory(struct sysinfo& sysInfo) {
    double totalVirtualMemory;
    totalVirtualMemory  = sysInfo.totalram;
    totalVirtualMemory += sysInfo.totalswap;
    totalVirtualMemory *= sysInfo.mem_unit;
    return totalVirtualMemory;
}

double MemoryResource::calcUsageVirtualMemory(struct sysinfo& sysInfo) {
    double usageVirtualMemory;
    usageVirtualMemory  = sysInfo.totalram - sysInfo.freeram;
    usageVirtualMemory += sysInfo.totalswap - sysInfo.freeswap;
    usageVirtualMemory *= sysInfo.mem_unit;
    return usageVirtualMemory;
}