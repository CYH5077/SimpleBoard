#include "resource/SystemInterfaceInfo.hpp"

SystemInterfaceInfo::SystemInterfaceInfo() {

}

SystemInterfaceInfo::~SystemInterfaceInfo() {

}

void SystemInterfaceInfo::setCPUInfo(CPUInterfaceInfo& interfaceInfo) {
    this->cpuInterfaceInfo = interfaceInfo;
}

const CPUInterfaceInfo& SystemInterfaceInfo::getCPUInfo() {
    return this->cpuInterfaceInfo;
}