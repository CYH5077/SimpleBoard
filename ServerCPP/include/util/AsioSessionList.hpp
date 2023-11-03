#pragma once

#include "util/AsioSession.hpp"

#include <vector>
#include <memory>

class AsioSessionList : public std::vector<std::shared_ptr<AsioSession>> {
public:
    void removeSession(std::shared_ptr<AsioSession> AsioSession);
};