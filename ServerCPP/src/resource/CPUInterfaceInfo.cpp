#include "resource/CPUInterfaceInfo.hpp"

CPUInterfaceInfo::CPUInterfaceInfo() {
    this->coreCount = 0;
}

CPUInterfaceInfo::~CPUInterfaceInfo() {

}

void CPUInterfaceInfo::setModel(std::string& model) {
    this->model = model;
}

void CPUInterfaceInfo::setVendor(std::string& vendor) {
    this->vendor = vendor;
}

void CPUInterfaceInfo::setCoreCount(int count) {
    this->coreCount = coreCount;
}

std::string CPUInterfaceInfo::getModel() {
    return this->model;
}

std::string CPUInterfaceInfo::getVendor() {
    return this->vendor;
}

int CPUInterfaceInfo::getCoreCount() {
    return this->coreCount;
}