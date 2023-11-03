#include "resource/SystemResource.hpp"
#include "resource/CPUResource.hpp"
#include "resource/MemoryResource.hpp"
#include "resource/NetworkResource.hpp"
#include "resource/ThreadCPUUsage.hpp"
#include "resource/ThreadMemoryUsage.hpp"
#include "resource/ThreadNetworkUsage.hpp"

#include "util/ThreadManager.hpp"

#include <thread>
#include <vector>
#include <future>

SystemResource::SystemResource() {

}

SystemResource::~SystemResource() {

}

bool SystemResource::readInterfaceInfo(SystemInterfaceInfo* interfaceInfo, Result* result) {
    if (interfaceInfo == nullptr ||
        result        == nullptr) {
        return false;        
    }

    return this->readSystemInterfaceInfo(interfaceInfo, result);
}

bool SystemResource::readUsageInfo(std::string& networkInterfaceName, SystemUsageInfo* usageInfo, ResultList* resultList) {
    if (usageInfo  == nullptr ||
        resultList == nullptr) {
        return false;
    }

    return this->readSystemUsageInfo(networkInterfaceName, usageInfo, resultList);
}

bool SystemResource::readSystemInterfaceInfo(SystemInterfaceInfo* interfaceInfo, Result* result) {
    CPUResource cpuResource;
    CPUInterfaceInfo cpuInterfaceInfo;
    if (!cpuResource.readCPUInterfaceInfo(&cpuInterfaceInfo, result)) {
        return result->isSuccess();
    }
    interfaceInfo->setCPUInfo(cpuInterfaceInfo);

    return result->success();
}

bool SystemResource::readSystemUsageInfo(std::string& networkInterfaceName, SystemUsageInfo* usageInfo, ResultList* resultList) {
    ThreadCPUUsage cpuThread;
    ThreadMemoryUsage memoryThread;
    ThreadNetworkUsage networkThread(networkInterfaceName);
    
    ThreadManager threadManager;
    threadManager.pushThread(cpuThread);
    threadManager.pushThread(memoryThread);
    threadManager.pushThread(networkThread);
    threadManager.start();
    threadManager.join();

    resultList->push_back(cpuThread.getResult());
    resultList->push_back(memoryThread.getResult());
    resultList->push_back(networkThread.getResult());
    if (!resultList->isSuccess()) {
        return false;
    }

    usageInfo->setCPUInfo(cpuThread.getReturn());
    usageInfo->setMemoryInfo(memoryThread.getReturn());
    usageInfo->setNetworkInfo(networkThread.getReturn());

    return resultList->success();
}
