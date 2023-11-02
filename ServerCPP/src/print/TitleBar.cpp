#include "print/TitleBar.hpp"

#include <sstream>

TitleBar::TitleBar(std::string&& title, TITLEBAR_TYPE type)
: PrintInterface(FONT_COLOR::DEFAULT_FONT_COLOR) {
    this->title = title;
    this->setType(type);
}   

TitleBar::~TitleBar() {

}

std::string TitleBar::text() const {
    switch (this->type) {
    case TITLEBAR_TYPE::MAIN:
        return this->getMainTitle();
    case TITLEBAR_TYPE::SUB:
        return this->getSubTitle();
    }

    return "";
}

void TitleBar::setType(TITLEBAR_TYPE type) {
    switch (type) {
    case TITLEBAR_TYPE::MAIN:
        this->setFontColor(FONT_COLOR::TITLEBAR_MAIN_FONT_COLOR); break;
    case TITLEBAR_TYPE::SUB:
        this->setFontColor(FONT_COLOR::TITLEBAR_SUB_FONT_COLOR);  break;      
    }

    this->type = type;
}

std::string TitleBar::getMainTitle() const {
    std::stringstream strStream;
    
    strStream << "========================================" 
              << " " << this->title << " " 
              << "========================================";

    return strStream.str();
}

std::string TitleBar::getSubTitle() const {
    std::stringstream strStream;

    strStream << "--------------------------------------------------------------------------------"
              << " " << this->title;

    return strStream.str();
}