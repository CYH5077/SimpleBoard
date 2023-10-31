#include <iostream>

#include "util/Result.hpp"
#include "resource/CPUResource.hpp"

int main(void) {
    CPUUsageInfo usageInfo;
    CPUResource cpuResource;

    Result result;
    if (!cpuResource.readCPUUsageInfo(&usageInfo, &result)) {
        std::cout << result.getErrorMessage() << std::endl;
    }
    
    return 0;
}