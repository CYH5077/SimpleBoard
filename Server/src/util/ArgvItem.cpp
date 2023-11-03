#include "util/ArgvItem.hpp"

ArgvItem::ArgvItem() {

}

ArgvItem::ArgvItem(std::string& option, std::string& value) {
    this->option = option;
    this->value = value;
}

ArgvItem::~ArgvItem() {

}

void ArgvItem::setOption(std::string& option) {
    this->option = option;
}

void ArgvItem::setValue(std::string& value) {
    this->value = value;
}

const std::string& ArgvItem::getOption() const {
    return this->option;
}

const std::string& ArgvItem::getValue() const {
    return this->value;
}