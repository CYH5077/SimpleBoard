#include "resource/CPUResource.hpp"

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <thread>
#include <chrono>

const std::string CPUResource::STAT_FILE_PATH = "/proc/stat";
const std::string CPUResource::CPUINFO_FILE_PATH = "/proc/cpuinfo";

CPUResource::CPUResource() {

}

CPUResource::~CPUResource() {
    
}

bool CPUResource::readCPUUsageInfo(CPUUsageInfo* cpuUsageInfo, Result* result) {
    if (cpuUsageInfo == nullptr ||
        result       == nullptr) {
        return false;
    }
    
    Result readStatFileResult;
    CPUUsageInfo beforeUsage;
    CPUUsageInfo afterUsage;
    if (!this->readStatFile(&beforeUsage, &readStatFileResult)) {
        return result->failed(readStatFileResult.getErrorCode(), readStatFileResult.getErrorMessage());
    }

    std::this_thread::sleep_for(std::chrono::seconds(1));

    if (!this->readStatFile(&afterUsage, &readStatFileResult)) {
        return result->failed(readStatFileResult.getErrorCode(), readStatFileResult.getErrorMessage());    
    }

    int cpuUsage = this->calcCPUUsage(beforeUsage, afterUsage);
    cpuUsageInfo->setUsage(cpuUsage);

    return result->success();
}

bool CPUResource::readCPUInterfaceInfo(CPUInterfaceInfo* cpuInterfaceInfo, Result* result) {
    if (cpuInterfaceInfo == nullptr ||
        result           == nullptr) {
        return false;
    }
    return this->readCPUInfoFile(cpuInterfaceInfo, result);
}

bool CPUResource::readStatFile(CPUUsageInfo* cpuUsageInfo, Result* result) {
    std::ifstream inputFileStream(this->STAT_FILE_PATH);
    if (!inputFileStream.is_open()) {
        return result->failed(-1, this->STAT_FILE_PATH + " 파일을 열지 못했습니다.");
    }

    std::string readData;
    std::getline(inputFileStream, readData);
    this->parseStat(readData, cpuUsageInfo);
    
    return result->success();
}

bool CPUResource::readCPUInfoFile(CPUInterfaceInfo* cpuInterfaceInfo, Result* result) {

    return result->success();
}

void CPUResource::parseStat(std::string& stat, CPUUsageInfo* cpuUsageInfo) {
    std::string startPosString = "cpu  ";
    std::string cpuUsageStr = stat.substr(startPosString.length(), stat.length() - startPosString.length());

    std::string token;
    std::vector<std::string> tokens;
    std::istringstream strStream(cpuUsageStr);
    while(std::getline(strStream, token, ' ')) {
        tokens.push_back(token);
    }

    cpuUsageInfo->setUser(std::stoi(tokens[0]));
    cpuUsageInfo->setNice(std::stoi(tokens[1]));
    cpuUsageInfo->setSystem(std::stoi(tokens[2]));
    cpuUsageInfo->setIdle(std::stoi(tokens[3]));
}

void CPUResource::parseCPUInfo(std::string& cpuInfo, CPUInterfaceInfo* cpuInterfaceInfo) {

}

int CPUResource::calcCPUUsage(CPUUsageInfo& beforeUsage, CPUUsageInfo& afterUsage) {
    int beforeNumerator = beforeUsage.getUser() + beforeUsage.getNice() + beforeUsage.getSystem();
    int afterNumerator  = afterUsage.getUser()  + afterUsage.getNice()  + afterUsage.getSystem();

    int beforeDenominator = beforeNumerator + beforeUsage.getIdle();
    int afterDenominator  = afterNumerator  + afterUsage.getIdle();

    int numerator   = beforeNumerator   - afterNumerator;
    int denominator = beforeDenominator - afterDenominator;

    double result = ((double)numerator / (double)denominator) * 100.0;
    return (int)result;
}