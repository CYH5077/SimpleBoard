#include <iostream>

#include "util/ArgvUtil.hpp"

#include "service/SystemResourceService.hpp"

void testService(ArgvUtil& argvUtil, SERVICE_TYPE serviceType) {
    SystemResourceService service;

    Result result;
    if (service.isValidArgv(serviceType, argvUtil, &result)) {
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

void testServerService(ArgvUtil& argvUtil) {
    SystemResourceService service;
}

int main(int argc, const char* argv[]) {
    ArgvUtil argvUtil;
    argvUtil.setArgument(argc, argv);

    testService(argvUtil, SERVICE_TYPE::SERVER);

    return 0;
}