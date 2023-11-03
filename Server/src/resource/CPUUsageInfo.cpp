#include "resource/CPUUsageInfo.hpp"

CPUUsageInfo::CPUUsageInfo() {
    this->cpuUsage = 0;
    
    this->user = 0;
    this->nice = 0;
    this->system = 0;
    this->idle = 0;
}

CPUUsageInfo::~CPUUsageInfo() {

}

void CPUUsageInfo::setUsage(const int usage) {
    this->cpuUsage = usage;

}
void CPUUsageInfo::setUser(const int user) {
    this->user = user;
}

void CPUUsageInfo::setNice(const int nice) {
    this->nice = nice;
}

void CPUUsageInfo::setSystem(const int system) {
    this->system = system;
}

void CPUUsageInfo::setIdle(const int idle) {
    this->idle = idle;
}

int CPUUsageInfo::getUsage() const {
    return this->cpuUsage;
}

int CPUUsageInfo::getUser() const {
    return this->user;
}

int CPUUsageInfo::getNice() const {
    return this->nice;
}

int CPUUsageInfo::getSystem() const {
    return this->system;
}

int CPUUsageInfo::getIdle() const {
    return this->idle;
}