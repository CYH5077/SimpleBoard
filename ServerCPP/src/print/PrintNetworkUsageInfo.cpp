#include "print/PrintNetworkUsageInfo.hpp"

#include <sstream>

PrintNetworkUsageInfo::PrintNetworkUsageInfo(NetworkUsageInfo& usageInfo)
: usageInfo(usageInfo)
, Print(FONT_COLOR::NETWORK_FONT_COLOR) {

}

PrintNetworkUsageInfo::~PrintNetworkUsageInfo() {

}

std::string PrintNetworkUsageInfo::text() const {
    std::stringstream strStream;

    strStream << "바이트 수신:    " << this->usageInfo.getRecvSize()   << " Bytes/s" << "\t\t\t"
              << "초당 패킷 수신: " << this->usageInfo.getRecvPacket() << " (1/s)"   << std::endl;

    strStream << "바이트 송신:    " << this->usageInfo.getSendSize()   << " Bytes/s" << "\t\t\t"
              << "초당 패킷 송신: " << this->usageInfo.getSendPacket() << " (1/s)"   << std::endl << std::endl;

    strStream << "초당 총 바이트: " << this->usageInfo.getTotalSize()   << " Bytes/s" << "\t\t\t"
              << "초당 총 패킷:   " << this->usageInfo.getTotalPacket() << " (1/s)"   << std::endl << std::endl;

    strStream << "수신 최고 기록:      " << this->usageInfo.getMaximumRecvSize()   << " KBytes/s" << "\t\t\t"
              << "수신 패킷 최고 기록: " << this->usageInfo.getMaximumRecvPacket() << " (1/s)"    << std::endl;
    
    strStream << "송신 최고 기록:      " << this->usageInfo.getMaximumSendSize()   << " KBytes/s" << "\t\t\t"
              << "송신 패킷 최고 기록: " << this->usageInfo.getMaximumSendPacket() << " (1/s)"    << std::endl;

    strStream << "바이트 최대 기록: " << this->usageInfo.getMaximumTotalSize()   << " KBytes/s" << "\t\t\t"
              << "패킷 최대 기록:   " << this->usageInfo.getMaximumTotalPacket() << " (1/s)";

    return strStream.str();
}