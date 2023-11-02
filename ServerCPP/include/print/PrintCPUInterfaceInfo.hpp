#pragma once

#include "print/PrintInterface.hpp"

#include "resource/CPUInterfaceInfo.hpp"
#include "resource/CPUUsageInfo.hpp"

class PrintCPUInterfaceInfo : public PrintInterface {
public:
    explicit PrintCPUInterfaceInfo(const CPUInterfaceInfo& interfaceInfo);
    virtual ~PrintCPUInterfaceInfo();

public:
    virtual std::string text() const override;


private:
    const CPUInterfaceInfo& interfaceInfo;
};