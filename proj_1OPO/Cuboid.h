#pragma once
#include "Figure.h"

class Cuboid : public Figure {
private:
    int length1, length2, length3;

public:
    Cuboid(double d, const std::string& o, int l1, int l2, int l3);
    void print() const override;
    bool matchesCondition(const std::string& condition) const override;
};