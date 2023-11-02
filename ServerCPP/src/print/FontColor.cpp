#include "print/FontColor.hpp"

#include <iostream>

const std::string FontColor::DEFAULT_FONT_COLOR = "\033[0m";
const std::string FontColor::CPU_FONT_COLOR     = "\033[1;35m";
const std::string FontColor::MEMORY_FONT_COLOR  = "\033[1;31m";
const std::string FontColor::NETWORK_FONT_COLOR = "\033[1;36m";

FontColor::FontColor() {
    this->fontColor = this->DEFAULT_FONT_COLOR;
}

FontColor::FontColor(FONT_COLOR fontColor) {
    this->setFontColor(fontColor);
}

FontColor::~FontColor() {

}

std::string FontColor::start() const {
    return this->fontColor;
}

std::string FontColor::end() const {
    return this->DEFAULT_FONT_COLOR;
}

void FontColor::setFontColor(FONT_COLOR fontColor) {
    switch (fontColor) {
    case FONT_COLOR::CPU_FONT_COLOR:
        this->fontColor = this->CPU_FONT_COLOR;     break;
    case FONT_COLOR::MEMORY_FONT_COLOR:
        this->fontColor = this->MEMORY_FONT_COLOR;  break;
    case FONT_COLOR::NETWORK_FONT_COLOR:
        this->fontColor = this->NETWORK_FONT_COLOR; break;
    defualt:
        this->fontColor = this->DEFAULT_FONT_COLOR;
    }
}