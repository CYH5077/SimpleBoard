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