#include "Cylinder.h"
#include <iostream>
#include <sstream>

Cylinder::Cylinder(double d, const std::string& o, int bx, int by, int h, int br) : Figure(d, o), baseX(bx), baseY(by), height(h), baseRadius(br) {}

void Cylinder::print() const {
    Figure::print();
    std::cout << "BaseX: " << baseX << ", BaseY: " << baseY << ", Height: " << height << ", BaseRadius: " << baseRadius << std::endl;
}

bool Cylinder::matchesCondition(const std::string& condition) const {
    std::istringstream iss(condition);
    std::string keyword;
    iss >> keyword;
    if (keyword == "Owner") {
        char op;
        std::string name;
        iss >> op >> name;
        if (name == getOwner() && op == '=') return true;
    }

    float cylinder_at;

    if (keyword == "BaseX") {
        cylinder_at = baseX;
    }
    else if (keyword == "BaseY") {
        cylinder_at = baseY;
    }
    else if (keyword == "Height") {
        cylinder_at = height;
    }
    else if (keyword == "BaseRadius") {
        cylinder_at = baseRadius;
    }
    else if (keyword == "Density") {
        cylinder_at = getDensity();
    }
    else return false;

    char op;
    float value;
    iss >> op >> value;

    switch (op) {
    case '>':
        return cylinder_at > value;
    case '<':
        return cylinder_at < value;
    case '=':
        return cylinder_at == value;
    default:
        return false;
    }
}