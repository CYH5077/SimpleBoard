#include "print/PrintSystsemResource.hpp"

#include <sstream>

PrintSystemInfo::PrintSystemInfo(SystemInterfaceInfo& interfaceInfo, SystemUsageInfo& usageInfo)
:interfaceInfo(interfaceInfo), usageInfo(usageInfo) {

}

PrintSystemInfo::~PrintSystemInfo() {

}

std::string PrintSystemInfo::text() const {
    std::stringstream strStream;

    return strStream.str();
}


