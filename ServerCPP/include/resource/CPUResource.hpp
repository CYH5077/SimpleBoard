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
    // Linux cpu 정보가 들어있는 파일 경로
    static const std::string STAT_FILE_PATH;
    static const std::string CPUINFO_FILE_PATH;

    // cpuinfo 파일에서 가져올 데이터의 라벨
    static const std::string CPUINFO_VENDOR_ID;
    static const std::string CPUINFO_MODEL_NAME;
    static const std::string CPUINFO_CORE_COUNT;

private:
    bool readStatFile(CPUUsageInfo* cpuUsageInfo, Result* result); // /proc/stat 파일을 읽어서 파싱
    bool readCPUInfoFile(CPUInterfaceInfo* cpuInterfaceInfo, Result* result); // /proc/cpuinfo 파일을 읽어서 파싱

    void parseStat(std::string& stat, CPUUsageInfo* cpuUsageInfo); 
    void parseCPUInfo(std::string& cpuInfo, CPUInterfaceInfo* cpuInterfaceInfo);

    int calcCPUUsage(CPUUsageInfo& beforeUsage, CPUUsageInfo& afterUsage);

private:

};
