#pragma once

#include "util/Result.hpp"

#include <vector>

class ResultList : public std::vector<Result> {
public:
    explicit ResultList();
    virtual ~ResultList();

public:
    bool success();

public: 
    // getter
    bool isSuccess();
    void getFailedList(ResultList* resultList);
};