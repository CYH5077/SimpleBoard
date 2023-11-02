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
    this->calcNetworkUsageMaximum(usageInfo);
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

void SystemUsageInfo::calcNetworkUsageMaximum(const NetworkUsageInfo& usageInfo) {
    int sendSize = usageInfo.getSendSize() >= this->networkUsageInfo.getMaximumSendSize() 
                 ? usageInfo.getSendSize() :  this->networkUsageInfo.getMaximumSendSize();
                 
    int recvSize = usageInfo.getRecvSize() >= this->networkUsageInfo.getMaximumRecvSize() 
                 ? usageInfo.getRecvSize() :  this->networkUsageInfo.getMaximumRecvSize();

    int sendPacket = usageInfo.getSendPacket() >= this->networkUsageInfo.getMaximumSendPacket() 
                   ? usageInfo.getSendPacket() :  this->networkUsageInfo.getMaximumSendPacket();
    
    int recvPacket = usageInfo.getRecvPacket() >= this->networkUsageInfo.getMaximumRecvPacket() 
                   ? usageInfo.getRecvPacket() :  this->networkUsageInfo.getMaximumRecvPacket();

    this->networkUsageInfo.setMaximumSendSize(sendSize);
    this->networkUsageInfo.setMaximumRecvSize(recvSize);
    this->networkUsageInfo.setMaximumSendPacket(sendPacket);
    this->networkUsageInfo.setMaximumRecvPacket(recvPacket);
}