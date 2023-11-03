#include "resource/SystemResourceSerializer.hpp"

#include <cstring>

void SystemResourceSerializer::serialize(SystemInterfaceInfo& interfaceInfo, SystemUsageInfo& usageInfo, ByteBuffer* byteBuffer) {
    size_t resourceStructSize = sizeof(struct ResourceInfo);

    struct ResourceInfo resourceInfo;
    std::memset(&resourceInfo, 0x00, resourceStructSize);
    SystemResourceSerializer::setResourceInfo(interfaceInfo, usageInfo, &resourceInfo);

    byteBuffer->clear();
    byteBuffer->resize(resourceStructSize);
    std::memcpy(byteBuffer->data(), &resourceInfo, resourceStructSize);
}


void SystemResourceSerializer::setResourceInfo(SystemInterfaceInfo& interfaceInfo, SystemUsageInfo& usageInfo, struct ResourceInfo* resourceInfo) {
    // Memory 정보 복사
    const MemoryUsageInfo& memoryUsageInfo = usageInfo.getMemoryInfo();
    resourceInfo->memoryTotalSize = memoryUsageInfo.getTotalMemory();
    resourceInfo->memoryUsageSize = memoryUsageInfo.getUsageMemory();
    resourceInfo->virtualMemoryTotalSize = memoryUsageInfo.getTotalVirtualMemory();
    resourceInfo->virtualMemoryUsageSize = memoryUsageInfo.getUsageVirtualMemory();

    // CPU 정보 복사
    const CPUUsageInfo& cpuUsageInfo = usageInfo.getCPUInfo();
    const CPUInterfaceInfo& cpuInterfaceInfo = interfaceInfo.getCPUInfo();
    resourceInfo->cpuUsage = cpuUsageInfo.getUsage();

    std::string cpuModel  = cpuInterfaceInfo.getModel();
    std::string cpuVendor = cpuInterfaceInfo.getVendor();
    std::string cpuCoreCount = std::to_string(cpuInterfaceInfo.getCoreCount());
    std::copy(cpuModel.begin()    , cpuModel.end()    , resourceInfo->cpuModel);
    std::copy(cpuCoreCount.begin(), cpuCoreCount.end(), resourceInfo->cpuCoreCount);
    std::copy(cpuVendor.begin()   , cpuVendor.end()   , resourceInfo->cpuVendor);

    // 네트워크 정보 복사
    const NetworkUsageInfo& networkUsageInfo = usageInfo.getNetworkInfo();
    resourceInfo->networkRecvSizePerSecond  = networkUsageInfo.getRecvSize();
    resourceInfo->networkSendSizePerSecond  = networkUsageInfo.getSendSize();
    resourceInfo->networkTotalSizePerSecond = networkUsageInfo.getTotalSize();
    resourceInfo->networkSendMaximumSize  = networkUsageInfo.getMaximumSendSize();
    resourceInfo->networkRecvMaximumSize  = networkUsageInfo.getMaximumRecvSize();
    resourceInfo->networkTotalMaximumSize = networkUsageInfo.getMaximumTotalSize();

    resourceInfo->networkRecvPacketPerSecond   = networkUsageInfo.getRecvPacket();
    resourceInfo->networkSendPacketPerSecond   = networkUsageInfo.getSendPacket();
    resourceInfo->networkTotalPacketPerSecond  = networkUsageInfo.getMaximumTotalPacket();
    resourceInfo->networkSendMaximumPacket  = networkUsageInfo.getMaximumSendPacket();
    resourceInfo->networkRecvMaximumPacket  = networkUsageInfo.getMaximumRecvPacket();
    resourceInfo->networkTotalMaximumPacket = networkUsageInfo.getMaximumTotalPacket();
}