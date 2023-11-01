#pragma once

class MemoryUsageInfo {
public:
    explicit MemoryUsageInfo();
    virtual ~MemoryUsageInfo();

public:
    void setTotalMemory(double totalMemory);
    void setUsageMemory(double usageMemory);
    void setTotalVirtualMemory(double totalVirtualMemory);
    void setUsageVirtualMemory(double UsageVirtualMemory);

    double getTotalMemory();
    double getUsageMemory();
    double getTotalVirtualMemory();
    double getUsageVirtualMemory();
    
private:
    // Memory
    double totalMemory;
    double usageMemory;
    
    // Virtual Memory
    double totalVirtualMemory;
    double usageVirtualMemory;
};