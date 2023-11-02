#include "resource/ThreadMemoryUsage.hpp"
#include "resource/MemoryResource.hpp"

ThreadMemoryUsage::ThreadMemoryUsage() {

}

ThreadMemoryUsage::~ThreadMemoryUsage() {

}

void ThreadMemoryUsage::run(MemoryUsageInfo* usageInfo, Result* result) {
    MemoryResource resource;
    if (!resource.readMemoryUsageInfo(usageInfo, result)) {
        // error
        return;
    }
    result->success();
}