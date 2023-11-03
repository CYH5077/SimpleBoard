#include "util/AsioSessionList.hpp"

void AsioSessionList::removeSession(std::shared_ptr<AsioSession> session) {
    auto iter = std::find(this->begin(), this->end(), session);
    if (iter == this->end()) {
        return;
    }
    this->erase(iter);
}