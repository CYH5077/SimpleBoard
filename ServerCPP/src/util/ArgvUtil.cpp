#include "util/ArgvUtil.hpp"

ArgvUtil ArgvUtil::instance;

ArgvUtil::ArgvUtil() {

}

ArgvUtil::~ArgvUtil() {

}

ArgvUtil* ArgvUtil::getInstance() {
    return &ArgvUtil::instance;
}

void ArgvUtil::setArgument(int argc, const char* argv[]) {
    for (int i = 0; i < argc; i++) {
        if (this->isOption(argv[i])) {
            std::string option = argv[i];
            std::string value  = "";
            if ((i + 1) < argc) {
                if (!this->isOption(argv[i + 1])) {
                    value = argv[i + 1];
                }
            }
            this->argvList.push_back(ArgvItem(option, value));
        }
    }
}

bool ArgvUtil::isValidOption(std::string& option) {
    ArgvItem item;
    return this->getValue(option, &item);
}

bool ArgvUtil::getValue(std::string& option, ArgvItem* argvItem) {
    if (argvItem == nullptr) {
        return false;
    }

    for (auto& item : this->argvList) {
        if (item.getOption() == option) {
            *argvItem = item;
            return true;
        }
    }
    return false;
}

bool ArgvUtil::isOption(const char* option) {
    if (option[0] != '-') {
        return false;
    }
    return true;
}