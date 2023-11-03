#pragma once

#include "resource/SystemInterfaceInfo.hpp"
#include "resource/SystemUsageInfo.hpp"

#include "util/ByteBuffer.hpp"

class SystemResourceSerializer {
public:
    static void serialize(SystemInterfaceInfo& interfaceInfo, SystemUsageInfo& usageInfo, ByteBuffer* byteBuffer);

private:
    struct ResourceInfo{
        double memoryTotalSize; 
        double memoryUsageSize;
        double virtualMemoryTotalSize;
        double virtualMemoryUsageSize;

        int cpuUsage;
        char cpuModel[50];
        char cpuCoreCount[3];
        char cpuVendor[20];

        int networkRecvSizePerSecond; //초당 받은 데이터.
        int networkSendSizePerSecond; //초당 전송한 데이터
        int networkTotalSizePerSecond; //초당 전송,받은 데이터
        int networkSendMaximumSize; //초당 최고치를 기록한 전송 바이트.
        int networkRecvMaximumSize; //초당 최고치를 기록한 수신 바이트
        int networkTotalMaximumSize; //초당 전송,받은 데이터의 최대 크기.

        int networkRecvPacketPerSecond; //초당 수신한 패킷
        int networkSendPacketPerSecond; //초당 전송한 패킷
        int networkTotalPacketPerSecond; //초당 전송 및 수신 패킷 
        int networkSendMaximumPacket; //초당 최고치를 기록한 전송패킷 수
        int networkRecvMaximumPacket; //초당 최고치를 기록한 수신패킷 수
        int networkTotalMaximumPacket; //초당 전송, 받은 패킷의 최대 개수.
    };

private:
    static void setResourceInfo(SystemInterfaceInfo& interfaceInfo, SystemUsageInfo& usageInfo, struct ResourceInfo* resourceInfo);
};