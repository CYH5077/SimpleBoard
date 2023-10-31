#pragma once

#include <string>


// CPU 모델명, 제조회사, CPU의 코어 개수를 저장할 class


class CPUInterfaceInfo {
public:
    explicit CPUInterfaceInfo();
    virtual ~CPUInterfaceInfo();

public:
    void setModel(std::string& model);
    void setVendor(std::string& vendor);
    void setCoreCount(int count);

    std::string getModel();
    std::string getVendor();
    int         getCoreCount();

private:
    std::string model;
    std::string vendor;
    int         coreCount;
};