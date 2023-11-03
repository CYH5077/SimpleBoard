#pragma once

#include "print/PrintInterface.hpp"

#include <string>

class ProgressBar : public PrintInterface {
public:
    explicit ProgressBar(std::string&& label, double value, double maxValue);
    explicit ProgressBar(std::string&& label, double value, double maxValue, FontColor&& fontColor);
    explicit ProgressBar(std::string&& label, double value, double maxValue, FONT_COLOR fontColor);
    virtual ~ProgressBar();

public:
    virtual std::string text() const override;

private:
    std::string label;

    double value;
    double maxValue;
};