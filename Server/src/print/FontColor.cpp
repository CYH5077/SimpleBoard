#include "print/FontColor.hpp"

#include <iostream>

const std::string FontColor::DEFAULT_FONT_COLOR = "\033[0m";
const std::string FontColor::CPU_FONT_COLOR     = "\033[1;35m";
const std::string FontColor::MEMORY_FONT_COLOR  = "\033[1;31m";
const std::string FontColor::NETWORK_FONT_COLOR = "\033[1;36m";
const std::string FontColor::TITLEBAR_MAIN_FONT_COLOR = "\033[1;32m";
const std::string FontColor::TITLEBAR_SUB_FONT_COLOR  = FontColor::DEFAULT_FONT_COLOR;

FontColor::FontColor() {
    this->fontColor = this->DEFAULT_FONT_COLOR;
}

FontColor::FontColor(FONT_COLOR fontColor) {
    this->setColor(fontColor);
}

FontColor::~FontColor() {

}

std::string FontColor::start() const {
    return this->fontColor;
}

std::string FontColor::end() const {
    return this->DEFAULT_FONT_COLOR;
}

void FontColor::setColor(FONT_COLOR fontColor) {
    switch (fontColor) {
    case FONT_COLOR::CPU_FONT_COLOR:
        this->fontColor = this->CPU_FONT_COLOR;     break;
    case FONT_COLOR::MEMORY_FONT_COLOR:
        this->fontColor = this->MEMORY_FONT_COLOR;  break;
    case FONT_COLOR::NETWORK_FONT_COLOR:
        this->fontColor = this->NETWORK_FONT_COLOR; break;
    case FONT_COLOR::TITLEBAR_MAIN_FONT_COLOR:
        this->fontColor = this->TITLEBAR_MAIN_FONT_COLOR; break;
    case FONT_COLOR::TITLEBAR_SUB_FONT_COLOR:
        this->fontColor = this->TITLEBAR_SUB_FONT_COLOR;  break;
    defualt: // DEFAULT_FONT_COLOR
        this->fontColor = this->DEFAULT_FONT_COLOR;
    }
}