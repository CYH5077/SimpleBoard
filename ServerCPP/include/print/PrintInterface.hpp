#pragma once 

#include <iostream>

#include "print/FontColor.hpp"

class PrintInterface {
public:
    explicit PrintInterface();
    explicit PrintInterface(FontColor& fontColor);
    explicit PrintInterface(FONT_COLOR fontColor);
    virtual ~PrintInterface();

public: // interface
    virtual std::string text() const = 0;

public:
    void setFontColor(FontColor&& fontColor);
    void setFontColor(FONT_COLOR fontColor);

public:
    friend std::ostream& operator<<(std::ostream& os, const PrintInterface& print) {
        os << print.fontColor.start() << print.text() << print.fontColor.end();
        return os;
    }

private:
    FontColor fontColor;
};