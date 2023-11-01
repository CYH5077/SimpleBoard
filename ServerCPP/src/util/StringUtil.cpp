#include "util/StringUtil.hpp"

StringUtil::StringUtil() {

}

StringUtil::~StringUtil() {

}

std::string StringUtil::removeFirstOf(std::string& str, char token) {
    int firstNotOfPos = str.find_first_not_of(token);
    if (firstNotOfPos == std::string::npos) {
        return str;
    }
    return str.substr(firstNotOfPos, str.length() - 1);
}

std::string StringUtil::removeLastOf(std::string& str, char token) {
    int lastNotOfPos = str.find_last_not_of(token);
    if (lastNotOfPos == std::string::npos ||
        lastNotOfPos == str.length() - 1) {
            return str;
    }
    return str.substr(0, lastNotOfPos + 1);
}

std::string StringUtil::removeFirstSpace(std::string& str) {
    return StringUtil::removeFirstOf(str, ' ');
}

std::string StringUtil::removeLastSpace(std::string& str) {
    return StringUtil::removeLastOf(str, ' ');
}

std::string StringUtil::removeLastTab(std::string& str) {
    return StringUtil::removeLastOf(str, '\t');
}