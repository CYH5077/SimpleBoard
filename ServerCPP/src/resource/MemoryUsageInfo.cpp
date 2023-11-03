#include "resource/MemoryUsageInfo.hpp"

MemoryUsageInfo::MemoryUsageInfo() {
    this->totalMemory = 0;
    this->usageMemory = 0;
    this->totalVirtualMemory = 0;
    this->usageVirtualMemory = 0;
}

MemoryUsageInfo::~MemoryUsageInfo() {

}

void MemoryUsageInfo::setTotalMemory(const double totalMemory) {
    this->totalMemory = totalMemory;
}

void MemoryUsageInfo::setUsageMemory(const double usageMemory) {
    this->usageMemory = usageMemory;
}

void MemoryUsageInfo::setTotalVirtualMemory(const double totalVirtualMemory) {
    this->totalVirtualMemory = totalVirtualMemory;
}

void MemoryUsageInfo::setUsageVirtualMemory(const double usageVirtualMemory) {
    this->usageVirtualMemory = usageVirtualMemory;
}

double MemoryUsageInfo::getTotalMemory() const {
    return this->totalMemory;
}

double MemoryUsageInfo::getUsageMemory() const {
    return this->usageMemory;
}

double MemoryUsageInfo::getTotalVirtualMemory() const {
    return this->totalVirtualMemory;
}

double MemoryUsageInfo::getUsageVirtualMemory() const {
    return this->usageVirtualMemory;
}

double MemoryUsageInfo::getTotalMemoryToKbytes() const {
    return this->totalMemory / 1024;
}

double MemoryUsageInfo::getUsageMemoryToKbytes() const {
    return this->usageMemory / 1024;
}

double MemoryUsageInfo::getTotalVirtualMemoryToKbytes() const {
    return this->totalVirtualMemory / 1024;
}

double MemoryUsageInfo::getUsageVirtualMemoryToKbytes() const {
    return this->usageVirtualMemory / 1024;
}