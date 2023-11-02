#pragma once

#include "print/Print.hpp"

#include "resource/NetworkUsageInfo.hpp"

class PrintNetworkUsageInfo : public Print {
public:
    explicit PrintNetworkUsageInfo(NetworkUsageInfo& usageInfo);
    virtual ~PrintNetworkUsageInfo();

public:
    virtual std::string text() const override;
    
private:
    NetworkUsageInfo& usageInfo;
};