#pragma once

#include "service/ServiceInterface.hpp"

class PrintService : public ServiceInterface {
public:
    explicit PrintService();
    virtual ~PrintService();

public:
    virtual bool run(ArgvUtil& argvUtil, SystemInterfaceInfo& interfaceInfo, SystemUsageInfo& usageInfo, ResultList* resultList) override;
};