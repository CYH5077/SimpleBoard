#include "service/ServiceFactory.hpp"
#include "service/PrintService.hpp"
#include "service/ServerService.hpp"

ServiceFactory::ServiceFactory() {

}

ServiceFactory::~ServiceFactory() {

}

std::shared_ptr<ServiceInterface> ServiceFactory::createService(SERVICE_TYPE serviceType) {
    std::shared_ptr<ServiceInterface> service;
    switch (serviceType) {
    case SERVICE_TYPE::LOCAL_PRINT:
        service = std::make_shared<PrintService>(); break;
    case SERVICE_TYPE::SERVER:
        service = std::make_shared<ServerService>(ServerService::DEFAULT_SERVICE_PORT); break;
    }
    return service;
}