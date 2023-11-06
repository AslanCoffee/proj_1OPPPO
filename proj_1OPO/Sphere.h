#pragma once
#include "Figure.h"

class Sphere : public Figure {
private:
    int radius;

public:
    Sphere(double d, const std::string& o, int r);
    void print() const override;
    bool matchesCondition(const std::string& condition) const override;
};