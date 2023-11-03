#pragma once

#include <string>


// CPU 모델명, 제조회사, CPU의 코어 개수를 저장할 class


class CPUInterfaceInfo {
public:
    explicit CPUInterfaceInfo();
    virtual ~CPUInterfaceInfo();

public:
    void setModel(const std::string& model);
    void setVendor(const std::string& vendor);
    void setCoreCount(const int coreCount);

    std::string getModel() const;
    std::string getVendor() const;
    int         getCoreCount() const;

private:
    std::string model;
    std::string vendor;
    int         coreCount;
};