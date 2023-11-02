#include "resource/ThreadCPUUsage.hpp"
#include "resource/CPUResource.hpp"

ThreadCPUUsage::ThreadCPUUsage() {

}

ThreadCPUUsage::~ThreadCPUUsage() {

}

void ThreadCPUUsage::run(CPUUsageInfo* usageInfo, Result* result) {
    CPUResource resource;
    if (!resource.readCPUUsageInfo(usageInfo, result)) {
        // error
        return;
    }
    result->success();
}