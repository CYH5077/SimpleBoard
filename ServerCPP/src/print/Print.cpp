#include "print/Print.hpp"

Print::Print() {
    
}

Print::Print(FontColor& fontColor) {
    this->fontColor = fontColor;
}

Print::Print(FONT_COLOR fontColor) {
    this->fontColor.setColor(fontColor);
}

Print::~Print() {

}

void Print::setFontColor(FontColor&& fontColor) {
    this->fontColor = fontColor;
}

void Print::setFontColor(FONT_COLOR fontColor) {
    this->fontColor.setColor(fontColor);
}
