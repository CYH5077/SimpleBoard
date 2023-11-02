#include "print/PrintCPUInterfaceInfo.hpp"

#include <sstream>

PrintCPUInterfaceInfo::PrintCPUInterfaceInfo(CPUInterfaceInfo& interfaceInfo)
: interfaceInfo(interfaceInfo)
, Print(FONT_COLOR::CPU_FONT_COLOR) {

}

PrintCPUInterfaceInfo::~PrintCPUInterfaceInfo() {

}

std::string PrintCPUInterfaceInfo::text() const {
    std::stringstream strStream;

    strStream << "CPU Vendor:\t" << this->interfaceInfo.getVendor() << std::endl;
    strStream << "CPU Model:\t"  << this->interfaceInfo.getModel()  << std::endl;
    strStream << "CPU Core count: " << this->interfaceInfo.getCoreCount();
    
    return strStream.str();
}
