#include <iostream>

#include "util/Result.hpp"

#include "print/ProgressBar.hpp"
#include "print/FontColor.hpp"
#include "print/PrintCPUInterfaceInfo.hpp"
#include "print/PrintMemoryUsageInfo.hpp"
#include "print/PrintNetworkUsageInfo.hpp"

#include "resource/CPUResource.hpp"
#include "resource/CPUInterfaceInfo.hpp"
#include "resource/MemoryResource.hpp"
#include "resource/MemoryUsageInfo.hpp"
#include "resource/NetworkResource.hpp"
#include "resource/NetworkUsageInfo.hpp"

void testProgressBar() {
    std::cout << ProgressBar("test 50%", 50.0, 100.0, FontColor(FONT_COLOR::CPU_FONT_COLOR)) << std::endl;
    std::cout << ProgressBar("test 100%", 100.0, 100.0) << std::endl;
}

void testPrintMemoryInfo() {
    MemoryResource resource;
    MemoryUsageInfo usageInfo;

    Result result;
    if (!resource.readMemoryUsageInfo(&usageInfo, &result)) {
        std::cout << result.getErrorMessage() << std::endl;
        return;
    }

    std::cout << PrintMemoryUsageInfo(usageInfo) << std::endl;
    std::cout << ProgressBar("사용량", usageInfo.getUsageMemoryToKbytes(), usageInfo.getTotalMemoryToKbytes(), FontColor(FONT_COLOR::MEMORY_FONT_COLOR)) << "\t\t"
              << ProgressBar("사용량", usageInfo.getUsageVirtualMemoryToKbytes() , usageInfo.getTotalVirtualMemoryToKbytes(), FontColor(FONT_COLOR::MEMORY_FONT_COLOR))
              << std::endl;
}

void testPrintNetworkInfo() {
    NetworkResource resource;
    NetworkUsageInfo usageInfo;

    std::string networkInterfaceName = "enp0s3";
    Result result;
    for (int i = 0; i < 2; i++) {
        if (!resource.readNetworkUsageInfoPerSecond(networkInterfaceName, &usageInfo, &result)) {
            std::cout << result.getErrorMessage() << std::endl;
            return;
        }
    }

    std::cout << PrintNetworkUsageInfo(usageInfo) << std::endl;
}

void testPrintCPUInfo() {
    CPUResource resource;
    CPUInterfaceInfo interfaceInfo;

    Result result;
    if (!resource.readCPUInterfaceInfo(&interfaceInfo, &result)) {
        std::cout << result.getErrorMessage() << std::endl;
        return;
    }

    CPUUsageInfo usageInfo;
    if (!resource.readCPUUsageInfo(&usageInfo, &result)) {
        std::cout << result.getErrorMessage() << std::endl;
        return;
    }

    std::cout << PrintCPUInterfaceInfo(interfaceInfo) << std::endl;
    std::cout << ProgressBar("CPU 사용량", (double)usageInfo.getUsage(), 100.0, FontColor(FONT_COLOR::CPU_FONT_COLOR))
              << std::endl;
}

int main(void) {
    testProgressBar();
    testPrintMemoryInfo();
    testPrintNetworkInfo();
    testPrintCPUInfo();
    return 0;
}