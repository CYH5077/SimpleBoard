#include "print/ProgressBar.hpp"

#include <sstream>

ProgressBar::ProgressBar(std::string&& label, double value, double maxValue) {
    this->label = label;
    this->value = value;
    this->maxValue = maxValue;
}


ProgressBar::ProgressBar(std::string&& label, double value, double maxValue, FontColor&& fontColor)
: PrintInterface(fontColor) {
    this->label = label;
    this->value = value;
    this->maxValue = maxValue;
}

ProgressBar::ProgressBar(std::string&& label, double value, double maxValue, FONT_COLOR fontColor)
: PrintInterface(fontColor) {
    this->label = label;
    this->value = value;
    this->maxValue = maxValue;
}

ProgressBar::~ProgressBar() {

}

std::string ProgressBar::text() const{
    std::stringstream strStream;
    strStream << this->label << " ";
    
    strStream << "[";
    double percent = (this->value * 100.0) / this->maxValue;
    int progress = (percent * 2) / 10;
    for (int i = 0; i < progress; i++) {
        strStream << "=";
    }
    for (int i = 0; i < 20 - progress; i++) {
        strStream << " ";
    }
    strStream << "] ";

    strStream << (int)percent << "%";

    return strStream.str();
}