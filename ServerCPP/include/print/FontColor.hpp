#pragma once

#include <string>

enum class FONT_COLOR {
    CPU_FONT_COLOR,
    MEMORY_FONT_COLOR,
    NETWORK_FONT_COLOR
};

class FontColor {
public:
    explicit FontColor();
    explicit FontColor(FONT_COLOR fontColor);
    virtual ~FontColor();

public:
    std::string start() const;
    std::string end() const;

public:
    static const std::string DEFAULT_FONT_COLOR;
    static const std::string CPU_FONT_COLOR;
    static const std::string MEMORY_FONT_COLOR;
    static const std::string NETWORK_FONT_COLOR;

private:
    void setFontColor(FONT_COLOR fontColor);
    
private:
    std::string fontColor;
};