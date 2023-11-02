#include "util/ArgvUtil.hpp"

ArgvUtil::ArgvUtil() {

}

ArgvUtil::~ArgvUtil() {

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

bool ArgvUtil::isValidOption(const std::string& option) {
    ArgvItem item;
    return this->getValue(option, &item);
}

bool ArgvUtil::getValue(const std::string& option, ArgvItem* argvItem) {
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

bool ArgvUtil::getValue(const std::string& option, std::string* value) {
    if (value == nullptr) {
        return false;
    }

    ArgvItem item;
    if (!this->getValue(option, &item)) {
        return false;
    }
    
    *value = item.getValue();
    return true;
}

bool ArgvUtil::isOption(const char* option) {
    if (option[0] != '-') {
        return false;
    }
    return true;
}