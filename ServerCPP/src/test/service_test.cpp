#include <iostream>

#include "util/ArgvUtil.hpp"

#include "service/SystemResourceService.hpp"

void testSystemResourceService(ArgvUtil& argvUtil) {
    SystemResourceService service;

    Result result;
    if (service.isValidArgv(SERVICE_TYPE::LOCAL_PRINT, argvUtil, &result)) {
        std::cout << result.getErrorMessage() << std::endl;
    }

    ResultList resultList;
    if (!service.run(SERVICE_TYPE::LOCAL_PRINT, argvUtil, &resultList)) {
        ResultList errorResultList;
        resultList.getFailedList(&errorResultList);
        for (auto& iter : errorResultList) {
            std::cout << iter.getErrorMessage() << std::endl;
        }
    }
}

int main(int argc, const char* argv[]) {
    ArgvUtil argvUtil;
    argvUtil.setArgument(argc, argv);

    testSystemResourceService(argvUtil);

    return 0;
}