#include <iostream>

#include "print/ProgressBar.hpp"
#include "print/FontColor.hpp"

void testProgressBar() {
    std::cout << ProgressBar("test 50%", 50.0, 100.0, FontColor(FONT_COLOR::CPU_FONT_COLOR)) << std::endl;
    std::cout << ProgressBar("test 100%", 100.0, 100.0) << std::endl;

}
int main(void) {
    testProgressBar();
    
    return 0;
}