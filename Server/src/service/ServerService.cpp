#include "service/ServerService.hpp"

#include "resource/SystemResourceSerializer.hpp"

const int ServerService::DEFAULT_SERVICE_PORT = 36555;

ServerService::ServerService(int servicePort)
: broadcastServerThread(servicePort) {

}

ServerService::~ServerService() {

}

bool ServerService::run(ArgvUtil& argvUtil, SystemInterfaceInfo& interfaceInfo, SystemUsageInfo& usageInfo, ResultList* resultList) {
    if (!this->broadcastServerThread.isRunning()) {
        this->broadcastServerThread.start();
    }

    ByteBuffer data;
    SystemResourceSerializer::serialize(interfaceInfo, usageInfo, &data);
    this->broadcastServerThread.broadcast(data, resultList);

    return resultList->success();
    //return true;
}

void ServerService::stop() {
    this->broadcastServerThread.stop();
    this->broadcastServerThread.join();
}