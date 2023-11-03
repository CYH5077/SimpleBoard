#include "util/ResultList.hpp"

ResultList::ResultList() {

}

ResultList::~ResultList() {

}

bool ResultList::success() {
    for (auto& iter : *this) {
        iter.success();
    }
    return true;
}

bool ResultList::isSuccess() {
    for (auto& iter : *this) {
        if (!iter.isSuccess()) {
            return false;
        }
    }

    return true;
}

void ResultList::getFailedList(ResultList* resultList) {
    if (resultList == nullptr) {
        return;
    }
    
    for (auto& iter : *this) {
        if (!iter.isSuccess()) {
            resultList->push_back(iter);
        }
    }
}