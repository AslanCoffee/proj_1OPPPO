#pragma once
#include "Figure.h"

class Cylinder : public Figure {
private:
    int baseX, baseY, height, baseRadius;

public:
    Cylinder(double d, const std::string& o, int bx, int by, int h, int br);
    void print() const override;
    bool matchesCondition(const std::string& condition) const override;
};