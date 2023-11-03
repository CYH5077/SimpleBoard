#include "main/Resource.hpp"

int main(int argc, const char* argv[]) {
    ArgvUtil argvUtil;
    argvUtil.setArgument(argc, argv);
    
    Resource::getInstance().start(argvUtil);

    return 0;
}