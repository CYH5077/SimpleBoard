#pragma once

#include "util/ArgvUtil.hpp"
#include "util/Result.hpp"
#include "util/ResultList.hpp"

#include "service/SystemResourceService.hpp"

class Resource {
public:
    static Resource& getInstance();

    void start(ArgvUtil& argvUtil);
    void stop();

private:
    void printHelp();

    bool getServiceType(ArgvUtil& argvUtil, SERVICE_TYPE* serviceType);

private:
    explicit Resource();
    virtual ~Resource();

    static Resource instance;

private:
    SystemResourceService service;
};