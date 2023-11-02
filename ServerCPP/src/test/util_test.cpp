#include <iostream>

#include "util/ArgvUtil.hpp"

void testArgvUtil() {
    int argc = 7;
    const char* argv[] = {
        "-a", "a-value",
        "-b",
        "-c",
        "-d", "d-value",
        "-e"
    };
    ArgvUtil argvUtil;
    argvUtil.setArgument(argc, argv);

    std::string a = "-a";
    if (!argvUtil.isValidOption(a)) {
        std::cout << "-a 옵션 못찾음 - 1" << std::endl;
        return;
    }

    ArgvItem item;
    if (!argvUtil.getValue(a, &item)) {
        std::cout << "-a 옵션 못찾음 - 2" << std::endl;
        return;
    }
    std::cout << "getValue(\"a\") result - " 
              << "option: " << item.getOption() << " " 
              << "value: "  << item.getValue()  << std::endl;;

    std::string f = "-f";
    if (argvUtil.isValidOption(f)) {
        std::cout << "-f 없어야되는데 있음" << std::endl;
        return;
    }

    

    
}

int main(int argc, char* argv[]) {
    testArgvUtil();

    return 0;
}