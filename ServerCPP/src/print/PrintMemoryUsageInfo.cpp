#include "print/PrintMemoryUsageInfo.hpp"

#include <sstream>

PrintMemoryUsageInfo::PrintMemoryUsageInfo(MemoryUsageInfo& usageInfo) 
: usageInfo(usageInfo) 
, Print(FONT_COLOR::MEMORY_FONT_COLOR) {

}

PrintMemoryUsageInfo::~PrintMemoryUsageInfo() {

}

std::string PrintMemoryUsageInfo::text() const {
    std::stringstream strStream;

    strStream << "총 메모리: "     << (int)this->usageInfo.getTotalMemoryToKbytes()        << " KBytes" << "\t\t\t" 
              << "총 가상메모리: " << (int)this->usageInfo.getTotalVirtualMemoryToKbytes() << " KBytes" << std::endl;

    strStream << "사용중인 메모리: "     << (int) this->usageInfo.getUsageMemoryToKbytes()       << " KBytes" << "\t\t\t"
              << "사용중인 가상메모리: " << (int)this->usageInfo.getUsageVirtualMemoryToKbytes() << " KBytes";

    return strStream.str();
}