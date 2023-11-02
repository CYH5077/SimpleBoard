#pragma once

#include "resource/SystemInterfaceInfo.hpp"

#include "service/ServiceFactory.hpp"
#include "service/ServiceInterface.hpp"
#include "service/ServiceList.hpp"

#include "util/ArgvUtil.hpp"
#include "util/ResultList.hpp"

#include <memory>
#include <vector>
#include <string>

class SystemResourceService {
public:
    explicit SystemResourceService();
    virtual ~SystemResourceService();

public:
    bool run(SERVICE_TYPE serviceType, ArgvUtil& argvUtil, ResultList* resultList);
    void stop();

    bool isValidArgv(SERVICE_TYPE serviceType, ArgvUtil& argvUtil, Result* result);

public:
    static const std::string OPTION_RUN_SERVER;
    static const std::string OPTION_RUN_LOCAL;
    static const std::string OPTION_NETWORK_INTERFACE_NAME;
    static const std::string OPTION_RUN_CLIENT;

private:
    bool initService(SERVICE_TYPE serviceType, Result* result);

    bool runResourceService(ArgvUtil& argvUtil, ResultList* resultList);

    bool readSystemInterfaceInfo(SystemInterfaceInfo* interfaceInfo, ResultList* resultList);
    bool readSystemUsageInfo(std::string& networkInterfaceName, SystemUsageInfo* usageInfo, ResultList* resultList);
    
    bool getNetworkInterfaceName(ArgvUtil& argvUtil, std::string* networkInterfaceName, Result* result);

    bool isValidLocalValid(ArgvUtil& argvUtil, Result* result);

private:
    ServiceList serviceList;

    bool isRunning;
};