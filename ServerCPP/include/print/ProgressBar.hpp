#pragma once

#include "print/Print.hpp"

#include <string>

class ProgressBar : public Print {
public:
    explicit ProgressBar(std::string&& label, double value, double maxValue);
    explicit ProgressBar(std::string&& label, double value, double maxValue, FontColor&& fontColor);
    virtual ~ProgressBar();

public:
    virtual std::string text() const override;

private:
    std::string label;

    double value;
    double maxValue;
};