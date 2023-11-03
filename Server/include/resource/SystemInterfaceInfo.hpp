#pragma once

#include "resource/CPUInterfaceInfo.hpp"

class SystemInterfaceInfo {
public:
    explicit SystemInterfaceInfo();
    virtual ~SystemInterfaceInfo();

public:
    // setter
    void setCPUInfo(CPUInterfaceInfo& cpuInterfaceInfo);

    // getter
    const CPUInterfaceInfo& getCPUInfo();

private:
    CPUInterfaceInfo cpuInterfaceInfo;
};