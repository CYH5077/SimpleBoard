#pragma once

#include <string>

#include "util/Result.hpp"
#include "resource/CPUInterfaceInfo.hpp"
#include "resource/CPUUsageInfo.hpp"

class CPUResource {
public:
    explicit CPUResource();
    virtual ~CPUResource();

public:
    bool readCPUUsageInfo(CPUUsageInfo* cpuUsageInfo, Result* result);
    bool readCPUInterfaceInfo(CPUInterfaceInfo* cpuInterfaceInfo, Result* result);


public:
    static const std::string STAT_FILE_PATH;
    static const std::string CPUINFO_FILE_PATH;

private:
    bool readStatFile(CPUUsageInfo* cpuUsageInfo, Result* result); // /proc/stat 파일을 읽어서 파싱
    bool readCPUInfoFile(CPUInterfaceInfo* cpuInterfaceInfo, Result* result); // /proc/cpuinfo 파일을 읽어서 파싱

    void parseStat(std::string& stat, CPUUsageInfo* cpuUsageInfo);
    void parseCPUInfo(std::string& cpuInfo, CPUInterfaceInfo* cpuInterfaceInfo);

    int calcCPUUsage(CPUUsageInfo& beforeUsage, CPUUsageInfo& afterUsage);
    
private:

};
