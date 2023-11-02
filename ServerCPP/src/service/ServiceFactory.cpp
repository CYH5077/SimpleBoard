#include "service/ServiceFactory.hpp"
#include "service/PrintService.hpp"

ServiceFactory::ServiceFactory() {

}

ServiceFactory::~ServiceFactory() {

}

std::shared_ptr<ServiceInterface> ServiceFactory::createService(SERVICE_TYPE serviceType) {
    std::shared_ptr<ServiceInterface> service;
    switch (serviceType) {
    case SERVICE_TYPE::LOCAL_PRINT:
        service = std::make_shared<PrintService>();
    }
    return service;
}