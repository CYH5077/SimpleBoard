#include <iostream>

#include "util/Result.hpp"
#include "resource/NetworkResource.hpp"
#include "resource/NetworkUsageInfo.hpp"
#include "resource/MemoryResource.hpp"
#include "resource/MemoryUsageInfo.hpp"
#include "resource/CPUInterfaceInfo.hpp"
#include "resource/CPUResource.hpp"
#include "resource/CPUUsageInfo.hpp"

static void testCPU() {
    CPUInterfaceInfo interfaceInfo;
    CPUUsageInfo usageInfo;
    CPUResource cpuResource;

    Result result;
    if (!cpuResource.readCPUInterfaceInfo(&interfaceInfo, &result)) {
        std::cout << result.getErrorMessage() << std::endl;
        return;
    }

    if (!cpuResource.readCPUUsageInfo(&usageInfo, &result)) {
        std::cout << result.getErrorMessage() << std::endl;
        return;
    }

    std::cout << "CPU Interface =================================" << std::endl;
    std::cout << "Model: " <<  interfaceInfo.getModel() << std::endl;
    std::cout << "Vendor: " << interfaceInfo.getVendor() << std::endl;
    std::cout << "Cores: " << interfaceInfo.getCoreCount() << std::endl << std::endl;

    std::cout << "CPU Usage =====================================" << std::endl;
    std::cout << "CPU 사용량: " << usageInfo.getUsage() << "%" << std::endl << std::endl;
}

static void testMemory() {
    MemoryUsageInfo usageInfo;
    MemoryResource memoryResource;

    Result result;
    if (!memoryResource.readMemoryUsageInfo(&usageInfo, &result)) {
        std::cout << result.getErrorMessage() << std::endl;
        return;
    }

    std::cout << "Memory Usage ====================================" << std::endl;
    std::cout << "Total memory: " << (int)usageInfo.getTotalMemoryToKbytes() << " kbytes" << std::endl;
    std::cout << "Usage memory: " << (int)usageInfo.getUsageMemoryToKbytes() << " kbytes" << std::endl;
    std::cout << "Total virtual memory: " << (int)usageInfo.getTotalVirtualMemoryToKbytes() << " kbytes" << std::endl;
    std::cout << "Usage virtual memory: " << (int)usageInfo.getUsageVirtualMemoryToKbytes() << " kbytes" << std::endl << std::endl; 
}

static void testNetwork() {
    NetworkUsageInfo usageInfo;
    NetworkResource networkResource;

    std::string networkInterfaceName = "enp0s3";
    Result result;
    if (!networkResource.readNetworkUsageInfoPerSecond(networkInterfaceName, &usageInfo, &result)) {
        std::cout << result.getErrorMessage() << std::endl;
    }

    std::cout << "Network =====================================" << std::endl;
    std::cout << usageInfo.getSendSize() << " bytes/s"<< std::endl;
    std::cout << usageInfo.getRecvSize() << " bytes/s" << std::endl;
    std::cout << usageInfo.getSendPacket() << " (1/s)" << std::endl;
    std::cout << usageInfo.getRecvPacket() << " (1/s)" << std::endl << std::endl;
}

int main(void) {
    testCPU();
    testMemory();
    testNetwork();

    return 0;
}