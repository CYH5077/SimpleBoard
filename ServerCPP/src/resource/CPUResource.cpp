#include "resource/CPUResource.hpp"
#include "util/StringUtil.hpp"

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <thread>
#include <chrono>


// linux cpu 정보가 들어있는 파일 경로
const std::string CPUResource::STAT_FILE_PATH    = "/proc/stat";
const std::string CPUResource::CPUINFO_FILE_PATH = "/proc/cpuinfo";

// cpuinfo 파일에서 가져올 데이터 라벨
const std::string CPUResource::CPUINFO_VENDOR_ID  = "vendor_id";
const std::string CPUResource::CPUINFO_MODEL_NAME = "model name";
const std::string CPUResource::CPUINFO_CORE_COUNT = "cpu cores";

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

    std::string readLine;
    std::getline(inputFileStream, readLine);
    this->parseStat(readLine, cpuUsageInfo);
    
    return result->success();
}

bool CPUResource::readCPUInfoFile(CPUInterfaceInfo* cpuInterfaceInfo, Result* result) {
    std::ifstream inputFileStream(this->CPUINFO_FILE_PATH);
    if (!inputFileStream.is_open()) {
        return result->failed(-1, this->CPUINFO_FILE_PATH + " 파일을 열지 못했습니다");
    }

    std::string readLine;
    std::vector<std::string> lines;
    while(std::getline(inputFileStream, readLine)) {
        if (readLine.length() == 0) {
            break;
        }
        this->parseCPUInfo(readLine, cpuInterfaceInfo);
    }

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
    std::string title = cpuInfo.substr(0, cpuInfo.find(":"));
    std::string value = cpuInfo.substr(cpuInfo.find(":") + 1, cpuInfo.length());

    title = StringUtil::removeLastTab(title);
    value = StringUtil::removeFirstSpace(value);

    if (title == this->CPUINFO_VENDOR_ID) {
        cpuInterfaceInfo->setVendor(value);
    } else if (title == this->CPUINFO_MODEL_NAME) {
        cpuInterfaceInfo->setModel(value);
    } else if (title == this->CPUINFO_CORE_COUNT) {
        cpuInterfaceInfo->setCoreCount(std::stoi(value));
    }
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