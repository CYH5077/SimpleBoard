#pragma once

class MemoryUsageInfo {
public:
    explicit MemoryUsageInfo();
    virtual ~MemoryUsageInfo();

public:
    void setTotalMemory(const double totalMemory);
    void setUsageMemory(const double usageMemory);
    void setTotalVirtualMemory(const double totalVirtualMemory);
    void setUsageVirtualMemory(const double UsageVirtualMemory);

    double getTotalMemory() const;
    double getUsageMemory() const;
    double getTotalVirtualMemory() const;
    double getUsageVirtualMemory() const;
    
    double getTotalMemoryToKbytes() const;
    double getUsageMemoryToKbytes() const;
    double getTotalVirtualMemoryToKbytes() const;
    double getUsageVirtualMemoryToKbytes() const;
    
private:
    // Memory
    double totalMemory;
    double usageMemory;
    
    // Virtual Memory
    double totalVirtualMemory;
    double usageVirtualMemory;
};