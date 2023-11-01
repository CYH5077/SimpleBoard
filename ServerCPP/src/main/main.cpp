#include <iostream>

#include "util/Result.hpp"
#include "resource/CPUResource.hpp"

int main(void) {
    CPUInterfaceInfo interfaceInfo;
    CPUResource cpuResource;

    Result result;
    if (!cpuResource.readCPUInterfaceInfo(&interfaceInfo, &result)) {
        std::cout << result.getErrorMessage() << std::endl;
    }
    std::cout << interfaceInfo.getVendor() << std::endl;
    std::cout << interfaceInfo.getModel() << std::endl;
    std::cout << interfaceInfo.getCoreCount() << std::endl;
    
    return 0;
}