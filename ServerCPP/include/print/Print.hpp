#pragma once 

#include <iostream>

#include "print/FontColor.hpp"

class Print {
public:
    explicit Print();
    explicit Print(FontColor& fontColor);
    virtual ~Print();

public: // interface
    virtual std::string text() const = 0;

public:
    friend std::ostream& operator<<(std::ostream& os, const Print& print) {
        os << print.fontColor.start() << print.text() << print.fontColor.end();
        return os;
    }

private:
    FontColor fontColor;
};