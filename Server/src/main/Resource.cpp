#include "main/Resource.hpp"

Resource Resource::instance;

Resource::Resource() {

}

Resource::~Resource() {
    this->stop();
}

Resource& Resource::getInstance() {
    return Resource::instance;
}

void Resource::start(ArgvUtil& argvUtil) {
    if (argvUtil.isEmpty() ||
        argvUtil.isValidOption("-h")) {
        this->printHelp();
        return;
    }    

    SERVICE_TYPE serviceType;
    if (!this->getServiceType(argvUtil, &serviceType)) {
        std::cout << "서비스 타입이 잘못되었습니다." << std::endl;
        this->printHelp();
        return;
    }

    Result result;
    if (!service.isValidArgv(serviceType, argvUtil, &result)) {
        std::cout << result.getErrorMessage() << std::endl;
    }

    ResultList resultList;
    if (!service.run(serviceType, argvUtil, &resultList)) {
        ResultList errorResultList;
        resultList.getFailedList(&errorResultList);
        for (auto& iter : errorResultList) {
            std::cout << iter.getErrorMessage() << std::endl;
        }
    }
}

void Resource::stop() {
    this->service.stop();
}

void Resource::printHelp() {
    std::cout << " - 로컬 시스템 리소스만 출력" << std::endl;
    std::cout << "ex) ./resource -l -n enp0s3" << std::endl;

    std::cout << " - 서버로 실행" << std::endl;
    std::cout << "ex) ./resource -s -n enp0s3" << std::endl;
}

bool Resource::getServiceType(ArgvUtil& argvUtil, SERVICE_TYPE* serviceType) {
    if (serviceType == nullptr) {
        return false;
    }

    if (argvUtil.isValidOption(SystemResourceService::OPTION_RUN_LOCAL)) {
        *serviceType = SERVICE_TYPE::LOCAL_PRINT;
        return true;
    } else if (argvUtil.isValidOption(SystemResourceService::OPTION_RUN_SERVER)) {
        *serviceType = SERVICE_TYPE::SERVER;
        return true;
    } 

    return false;
    
}