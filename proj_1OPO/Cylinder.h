#pragma once
#include "Figure.h"

class Cylinder : public Figure {
private:
    int baseX, baseY, height, baseRadius;

public:
    Cylinder(double d, const std::string& o, double bx, double by, double h, double br);
    void print() const override;
    bool matchesCondition(const std::string& condition) const override;
};