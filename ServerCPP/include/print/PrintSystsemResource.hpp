#pragma once

#include "print/Print.hpp"

#include "resource/SystemInterfaceInfo.hpp"
#include "resource/SystemUsageInfo.hpp"
#include "resource/CPUInterfaceInfo.hpp"
#include "resource/CPUUsageInfo.hpp"
#include "resource/MemoryUsageInfo.hpp"
#include "resource/NetworkUsageInfo.hpp"

class PrintSystemInfo : public Print {
public:
    explicit PrintSystemInfo(SystemInterfaceInfo& interfaceInfo, SystemUsageInfo& usageInfo);
    virtual ~PrintSystemInfo();

public:
    virtual std::string text() const;

public:
    void printCPUInfo(const CPUInterfaceInfo& interfaceInfo, const CPUUsageInfo& usageInfo);
    void printMemoryInfo(const MemoryUsageInfo& usageInfo);
    void printNetworkInfo(const NetworkUsageInfo& usageInfo);

private:
    const SystemInterfaceInfo& interfaceInfo;
    const SystemUsageInfo&     usageInfo;
};