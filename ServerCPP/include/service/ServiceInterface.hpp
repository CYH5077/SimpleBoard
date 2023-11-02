#pragma once

#include "util/ResultList.hpp"
#include "util/ArgvUtil.hpp"

#include "resource/SystemInterfaceInfo.hpp"
#include "resource/SystemUsageInfo.hpp"

class ServiceInterface {
public:
    explicit ServiceInterface();
    virtual ~ServiceInterface();

public:
    virtual bool run(ArgvUtil& argvUtil, SystemInterfaceInfo& interfaceInfo, SystemUsageInfo& usageInfo, ResultList* resultList) = 0;
    
private:

};
