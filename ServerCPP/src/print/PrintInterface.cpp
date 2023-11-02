#include "print/PrintInterface.hpp"

PrintInterface::PrintInterface() {
    
}

PrintInterface::PrintInterface(FontColor& fontColor) {
    this->fontColor = fontColor;
}

PrintInterface::PrintInterface(FONT_COLOR fontColor) {
    this->fontColor.setColor(fontColor);
}

PrintInterface::~PrintInterface() {

}

void PrintInterface::setFontColor(FontColor&& fontColor) {
    this->fontColor = fontColor;
}

void PrintInterface::setFontColor(FONT_COLOR fontColor) {
    this->fontColor.setColor(fontColor);
}
