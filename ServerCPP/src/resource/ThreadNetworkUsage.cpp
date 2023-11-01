#include "resource/ThreadNetworkUsage.hpp"
#include "resource/NetworkResource.hpp"

ThreadNetworkUsage::ThreadNetworkUsage(std::string& networkInterfaceName) {
    this->networkInterfaceName = networkInterfaceName;
}

ThreadNetworkUsage::~ThreadNetworkUsage() {

}

void ThreadNetworkUsage::run(NetworkUsageInfo* usageInfo, Result* result) {
    NetworkResource resource;
    if (!resource.readNetworkUsageInfoPerSecond(this->networkInterfaceName, usageInfo, result)) {
        // error
    }

    result->success();
}