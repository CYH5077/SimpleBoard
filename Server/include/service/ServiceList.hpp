#pragma once

#include "service/ServiceInterface.hpp"

#include <vector>
#include <memory>

class ServiceList : public std::vector<std::shared_ptr<ServiceInterface>> {

};