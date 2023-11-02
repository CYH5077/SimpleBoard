#pragma once

#include "service/ServiceInterface.hpp"

#include <memory>

enum class SERVICE_TYPE {
    LOCAL_PRINT,
};

class ServiceFactory {
public:
    explicit ServiceFactory();
    virtual ~ServiceFactory();

public:
    static std::shared_ptr<ServiceInterface> createService(SERVICE_TYPE serviceType);
};