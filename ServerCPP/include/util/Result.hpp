#pragma once

#include <string>

class Result {
public:
    explicit Result();
    virtual ~Result();

public:
    bool success();
    bool failed(int errorCode, std::string&& errorMessage);
    void clear();

public: 
    // setter
    void setResult(Result& result);

    // getter
    bool        isSuccess();
    int         getErrorCode();
    std::string getErrorMessage();
    
private:
    bool        result;
    int         errorCode;
    std::string errorMessage;
};