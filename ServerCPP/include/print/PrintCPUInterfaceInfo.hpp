#pragma once

#include "print/Print.hpp"

#include "resource/CPUInterfaceInfo.hpp"
#include "resource/CPUUsageInfo.hpp"

class PrintCPUInterfaceInfo : public Print {
public:
    explicit PrintCPUInterfaceInfo(CPUInterfaceInfo& interfaceInfo);
    virtual ~PrintCPUInterfaceInfo();

public:
    virtual std::string text() const override;


private:
    CPUInterfaceInfo& interfaceInfo;
};