#pragma once

#include "print/PrintInterface.hpp"

#include "resource/MemoryUsageInfo.hpp"

class PrintMemoryUsageInfo : public PrintInterface {
public:
    explicit PrintMemoryUsageInfo(const MemoryUsageInfo& usageInfo);
    virtual ~PrintMemoryUsageInfo();

public:
    virtual std::string text() const override;

private:
    const MemoryUsageInfo& usageInfo;
};