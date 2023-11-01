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

double MemoryUsageInfo::getTotalMemoryToKbytes() {
    return this->totalMemory / 1024;
}

double MemoryUsageInfo::getUsageMemoryToKbytes() {
    return this->usageMemory / 1024;
}

double MemoryUsageInfo::getTotalVirtualMemoryToKbytes() {
    return this->totalVirtualMemory / 1024;
}

double MemoryUsageInfo::getUsageVirtualMemoryToKbytes() {
    return this->usageVirtualMemory / 1024;
}