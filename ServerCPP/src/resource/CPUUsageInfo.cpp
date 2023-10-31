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

void CPUUsageInfo::setUsage(int usage) {
    this->cpuUsage = usage;

}
void CPUUsageInfo::setUser(int user) {
    this->user = user;
}

void CPUUsageInfo::setNice(int nice) {
    this->nice = nice;
}

void CPUUsageInfo::setSystem(int system) {
    this->system = system;
}

void CPUUsageInfo::setIdle(int idle) {
    this->idle = idle;
}

int CPUUsageInfo::getUsage() {
    return this->cpuUsage;
}

int CPUUsageInfo::getUser() {
    return this->user;
}

int CPUUsageInfo::getNice() {
    return this->nice;
}

int CPUUsageInfo::getSystem() {
    return this->system;
}

int CPUUsageInfo::getIdle() {
    return this->idle;
}