#include "resource/MemoryUsageInfo.hpp"

MemoryUsageInfo::MemoryUsageInfo() {
    this->totalMemory = 0;
    this->usageMemory = 0;
    this->totalVirtualMemory = 0;
    this->usageVirtualMemory = 0;
}

MemoryUsageInfo::~MemoryUsageInfo() {

}

void MemoryUsageInfo::setTotalMemory(double totalMemory) {
    this->totalMemory = totalMemory;
}

void MemoryUsageInfo::setUsageMemory(double usageMemory) {
    this->usageMemory = usageMemory;
}

void MemoryUsageInfo::setTotalVirtualMemory(double totalVirtualMemory) {
    this->totalVirtualMemory = totalVirtualMemory;
}

void MemoryUsageInfo::setUsageVirtualMemory(double usageVirtualMemory) {
    this->usageVirtualMemory = usageVirtualMemory;
}

double MemoryUsageInfo::getTotalMemory() {
    return this->totalMemory;
}

double MemoryUsageInfo::getUsageMemory() {
    return this->usageMemory;
}

double MemoryUsageInfo::getTotalVirtualMemory() {
    return this->totalVirtualMemory;
}

double MemoryUsageInfo::getUsageVirtualMemory() {
    return this->usageVirtualMemory;
}