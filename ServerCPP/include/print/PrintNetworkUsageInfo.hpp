#pragma once

#include "print/PrintInterface.hpp"

#include "resource/NetworkUsageInfo.hpp"

class PrintNetworkUsageInfo : public PrintInterface {
public:
    explicit PrintNetworkUsageInfo(const NetworkUsageInfo& usageInfo);
    virtual ~PrintNetworkUsageInfo();

public:
    virtual std::string text() const override;
    
private:
    const NetworkUsageInfo& usageInfo;
};