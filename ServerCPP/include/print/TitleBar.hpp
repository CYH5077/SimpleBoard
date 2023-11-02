#pragma once

#include "print/Print.hpp"

enum class TITLEBAR_TYPE {
    MAIN,
    SUB
};

class TitleBar : public Print {
public:
    explicit TitleBar(std::string&& title, TITLEBAR_TYPE type);
    virtual ~TitleBar();

public:
    virtual std::string text() const override;

public:
    void setType(TITLEBAR_TYPE type);
    
    std::string getMainTitle() const;
    std::string getSubTitle() const;

private:
    TITLEBAR_TYPE type;

    std::string title;
};