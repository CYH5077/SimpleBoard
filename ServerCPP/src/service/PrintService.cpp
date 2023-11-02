#include "service/PrintService.hpp"

#include "print/FontColor.hpp"
#include "print/TitleBar.hpp"
#include "print/ProgressBar.hpp"
#include "print/PrintCPUInterfaceInfo.hpp"
#include "print/PrintMemoryUsageInfo.hpp"
#include "print/PrintNetworkUsageInfo.hpp"

#include <iostream>

PrintService::PrintService() {

}

PrintService::~PrintService() {

}

bool PrintService::run(ArgvUtil& argvUtil, SystemInterfaceInfo& interfaceInfo, SystemUsageInfo& usageInfo, ResultList* resultList) {
    system("clear");
    
    // 타이틀바 출력
    std::cout << TitleBar("System Resource", TITLEBAR_TYPE::MAIN) << std::endl << std::endl;
    
    // 메모리 정보 출력
    const MemoryUsageInfo& memoryUsageinfo = usageInfo.getMemoryInfo();
    std::cout << TitleBar("Memory", TITLEBAR_TYPE::SUB) << std::endl;
    std::cout << PrintMemoryUsageInfo(memoryUsageinfo)  << std::endl;
    std::cout << ProgressBar("사용량", memoryUsageinfo.getUsageMemoryToKbytes(), memoryUsageinfo.getTotalMemoryToKbytes(), FONT_COLOR::MEMORY_FONT_COLOR) << "\t\t"
              << ProgressBar("사용량", memoryUsageinfo.getUsageVirtualMemoryToKbytes() , memoryUsageinfo.getTotalVirtualMemoryToKbytes(), FONT_COLOR::MEMORY_FONT_COLOR)
              << std::endl;
    
    // 네트워크 정보 출력
    const NetworkUsageInfo& networkUsageInfo = usageInfo.getNetworkInfo();
    std::cout << TitleBar("Network", TITLEBAR_TYPE::SUB) << std::endl;
    std::cout << PrintNetworkUsageInfo(networkUsageInfo) << std::endl;

    // CPU 정보 출력
    const CPUUsageInfo& cpuUsageInfo = usageInfo.getCPUInfo();
    const CPUInterfaceInfo& cpuInterfaceInfo = interfaceInfo.getCPUInfo();
    std::cout << TitleBar("CPU", TITLEBAR_TYPE::SUB) << std::endl;
    std::cout << PrintCPUInterfaceInfo(cpuInterfaceInfo) << std::endl;
    std::cout << ProgressBar("CPU 사용량", (double)cpuUsageInfo.getUsage(), 100.0, FONT_COLOR::CPU_FONT_COLOR) << std::endl;

    return resultList->success();
}