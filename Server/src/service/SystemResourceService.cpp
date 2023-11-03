#include "service/SystemResourceService.hpp"

#include "resource/SystemResource.hpp"
#include "resource/SystemUsageInfo.hpp"
#include "resource/SystemInterfaceInfo.hpp"

#include "util/ArgvUtil.hpp"

const std::string SystemResourceService::OPTION_RUN_SERVER = "-s";
const std::string SystemResourceService::OPTION_RUN_LOCAL  = "-l";
const std::string SystemResourceService::OPTION_NETWORK_INTERFACE_NAME = "-n";
const std::string SystemResourceService::OPTION_RUN_CLIENT = "-c";

SystemResourceService::SystemResourceService() {
    this->isRunning = true;
}

SystemResourceService::~SystemResourceService() {

}

bool SystemResourceService::run(SERVICE_TYPE serviceType, ArgvUtil& argvUtil, ResultList* resultList) {
    if (resultList == nullptr) {
        return false;
    }

    Result result;
    if (!this->initService(serviceType, &result)) {
        resultList->push_back(result);
        return resultList->isSuccess();
    }

    return this->runResourceService(argvUtil, resultList);
}

void SystemResourceService::stop() {
    this->isRunning = false;
    for (auto& iter : this->serviceList) {
        iter->stop();
    }
}

bool SystemResourceService::isValidArgv(SERVICE_TYPE serviceType, ArgvUtil& argvUtil, Result* result) {
    if (result == nullptr) {
        return false;
    }

    switch (serviceType) {
    case SERVICE_TYPE::LOCAL_PRINT:
        return this->isValidLocalArgv(argvUtil, result);
    case SERVICE_TYPE::SERVER:
        return this->isValidServerArgv(argvUtil, result);
    }

    return result->failed(-1, "알 수 없는 SERVICE_TYPE");
}

bool SystemResourceService::initService(SERVICE_TYPE serviceType, Result* result) {
    try {
        switch (serviceType) {
        case SERVICE_TYPE::LOCAL_PRINT:
            this->serviceList.push_back(ServiceFactory::createService(SERVICE_TYPE::LOCAL_PRINT));
            break;
        case SERVICE_TYPE::SERVER:
            this->serviceList.push_back(ServiceFactory::createService(SERVICE_TYPE::LOCAL_PRINT));
            this->serviceList.push_back(ServiceFactory::createService(SERVICE_TYPE::SERVER));
            break;
        }
    } catch (std::bad_alloc& e) {
        return result->failed(-1, e.what());
    }
    return result->success();
}

bool SystemResourceService::runResourceService(ArgvUtil& argvUtil, ResultList* resultList) {
    Result result;
    SystemUsageInfo usageInfo;
    SystemInterfaceInfo interfaceInfo;

    // argvUtil에서 네트워크 인터페이스 이름을 가져옴.
    std::string networkInterfaceName;
    if (!this->getNetworkInterfaceName(argvUtil, &networkInterfaceName, &result)) {
        resultList->push_back(result);
        return resultList->isSuccess();
    }
    
    // 시스템 인터페이스 정보를 읽음
    if (!this->readSystemInterfaceInfo(&interfaceInfo, resultList)) {
        return resultList->isSuccess();
    }

    while (this->isRunning) {
        if (!this->readSystemUsageInfo(networkInterfaceName, &usageInfo, resultList)) {
            return resultList->isSuccess();
        }

        for (auto& iter : this->serviceList) {
            if (!iter->run(argvUtil, interfaceInfo, usageInfo, resultList)) {
                return resultList->isSuccess();
            }
        }
    }

    return resultList->success();
}

bool SystemResourceService::readSystemInterfaceInfo(SystemInterfaceInfo* interfaceInfo, ResultList* resultList) {
    Result result;
    SystemResource resource;

    if (!resource.readInterfaceInfo(interfaceInfo, &result)) {
        resultList->push_back(result);
        return resultList->isSuccess();
    }
    return resultList->success();
}

bool SystemResourceService::readSystemUsageInfo(std::string& networkInterfaceName, SystemUsageInfo* usageInfo, ResultList* resultList) {
    SystemResource resource;
    if (!resource.readUsageInfo(networkInterfaceName, usageInfo, resultList)) {
        return resultList->isSuccess();
    }
    return resultList->success();
}

bool SystemResourceService::getNetworkInterfaceName(ArgvUtil& argvUtil, std::string* networkInterfaceName, Result* result) {
    if (!argvUtil.getValue(this->OPTION_NETWORK_INTERFACE_NAME, networkInterfaceName)) {
        return result->failed(-1, "네트워크 인터페이스 정보를 찾을 수 없습니다. 다음과 같은 옵션을 사용하세요 ex:) -n enp2s0");
    }
    return result->success();
}

bool SystemResourceService::isValidLocalArgv(ArgvUtil& argvUtil, Result* result) {
    if (!argvUtil.isValidOption(this->OPTION_RUN_LOCAL)) {
        return result->failed(-1, this->OPTION_RUN_LOCAL + " 가 설정되지 않았습니다.");
    } 
    
    if (!argvUtil.isValidOption(this->OPTION_NETWORK_INTERFACE_NAME)) {
        return result->failed(-1, this->OPTION_NETWORK_INTERFACE_NAME + "네트워크 인터페이스 정보를 찾을 수 없습니다. 다음과 같은 옵션을 사용하세요 ex:) -n enp2s0");
    }

    return result->success();
}

bool SystemResourceService::isValidServerArgv(ArgvUtil& argvUtil, Result* result) {
    if (!argvUtil.isValidOption(this->OPTION_RUN_SERVER)) {
        return result->failed(-1, this->OPTION_RUN_SERVER +  " 가 설정되지 않았습니다.");
    }

    if (!argvUtil.isValidOption(this->OPTION_NETWORK_INTERFACE_NAME)) {
        return result->failed(-1, this->OPTION_NETWORK_INTERFACE_NAME + "네트워크 인터페이스 정보를 찾을 수 없습니다. 다음과 같은 옵션을 사용하세요 ex:) -n enp2s0");
    }

    return result->success();
}