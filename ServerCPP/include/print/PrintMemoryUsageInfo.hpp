#pragma once

#include "print/Print.hpp"

#include "resource/MemoryUsageInfo.hpp"

class PrintMemoryUsageInfo : public Print {
public:
    explicit PrintMemoryUsageInfo(MemoryUsageInfo& usageInfo);
    virtual ~PrintMemoryUsageInfo();

public:
    virtual std::string text() const override;

private:
    MemoryUsageInfo& usageInfo;
};