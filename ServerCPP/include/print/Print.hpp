#pragma once 

#include <iostream>

#include "print/FontColor.hpp"

class Print {
public:
    explicit Print();
    explicit Print(FontColor& fontColor);
    explicit Print(FONT_COLOR fontColor);
    virtual ~Print();

public: // interface
    virtual std::string text() const = 0;

public:
    void setFontColor(FontColor&& fontColor);
    void setFontColor(FONT_COLOR fontColor);

public:
    friend std::ostream& operator<<(std::ostream& os, const Print& print) {
        os << print.fontColor.start() << print.text() << print.fontColor.end();
        return os;
    }

private:
    FontColor fontColor;
};