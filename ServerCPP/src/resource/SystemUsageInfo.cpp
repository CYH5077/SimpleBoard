#include "resource/SystemUsageInfo.hpp"

SystemUsageInfo::SystemUsageInfo() {

}

SystemUsageInfo::~SystemUsageInfo() {

}

void SystemUsageInfo::setCPUInfo(const CPUUsageInfo& usageInfo) {
    this->cpuUsageInfo = usageInfo;
}

void SystemUsageInfo::setMemoryInfo(const MemoryUsageInfo& usageInfo) {
    this->memoryUsageInfo = usageInfo;
}

void SystemUsageInfo::setNetworkInfo(const NetworkUsageInfo& usageInfo) {
    this->networkUsageInfo = usageInfo;
}

const CPUUsageInfo& SystemUsageInfo::getCPUInfo() {
    return this->cpuUsageInfo;
}

const MemoryUsageInfo& SystemUsageInfo::getMemoryInfo() {
    return this->memoryUsageInfo;
}

const NetworkUsageInfo& SystemUsageInfo::getNetworkInfo() {
    return this->networkUsageInfo;
}