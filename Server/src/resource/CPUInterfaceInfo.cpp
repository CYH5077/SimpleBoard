#include "resource/CPUInterfaceInfo.hpp"

CPUInterfaceInfo::CPUInterfaceInfo() {
    this->coreCount = 0;
}

CPUInterfaceInfo::~CPUInterfaceInfo() {

}

void CPUInterfaceInfo::setModel(const std::string& model) {
    this->model = model;
}

void CPUInterfaceInfo::setVendor(const std::string& vendor) {
    this->vendor = vendor;
}

void CPUInterfaceInfo::setCoreCount(const int coreCount) {
    this->coreCount = coreCount;
}

std::string CPUInterfaceInfo::getModel() const {
    return this->model;
}

std::string CPUInterfaceInfo::getVendor() const {
    return this->vendor;
}

int CPUInterfaceInfo::getCoreCount() const {
    return this->coreCount;
}