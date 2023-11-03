#pragma once

#include "service/ServiceInterface.hpp"

#include "util/AsioBroadcastServerThread.hpp"

class ServerService : public ServiceInterface {
public:
    explicit ServerService(int servicePort);
    virtual ~ServerService();

public:
    virtual bool run(ArgvUtil& argvUtil, SystemInterfaceInfo& interfaceInfo, SystemUsageInfo& usageInfo, ResultList* resultList) override;
    virtual void stop() override;

public:
    static const int DEFAULT_SERVICE_PORT;
    
private:
    AsioBroadcastServerThread broadcastServerThread;
};