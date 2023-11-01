#include <iostream>

#include "util/Result.hpp"
#include "resource/MemoryUsageInfo.hpp"
#include "resource/MemoryResource.hpp"

int main(void) {
    MemoryUsageInfo memoryUsageInfo;
    MemoryResource memoryResource;

    Result result;
    if (!memoryResource.readMemoryUsageInfo(&memoryUsageInfo, &result)) {
        std::cout << "failed - " << result.getErrorMessage() << std::endl;
    }

    std::cout << memoryUsageInfo.getTotalMemory() << std::endl;
    std::cout << memoryUsageInfo.getUsageMemory() << std::endl;
    std::cout << memoryUsageInfo.getTotalVirtualMemory() << std::endl;
    std::cout << memoryUsageInfo.getUsageVirtualMemory() << std::endl;

    return 0;
}