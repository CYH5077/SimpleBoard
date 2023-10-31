#include "util/Result.hpp"

Result::Result() {
    this->result = true;
    this->errorCode = 0;
}

Result::~Result() {

}

bool Result::success() {
    this->result = true;
    
    return true;
}

bool Result::failed(int errorCode, std::string&& errorMessage) {
    this->result = false;
    this->errorCode = errorCode;
    this->errorMessage = errorMessage;

    return false;
}

bool Result::isSuccess() {
    return this->result;
}

int Result::getErrorCode() {
    return this->errorCode;
}

std::string Result::getErrorMessage() {
    return this->errorMessage;
}

