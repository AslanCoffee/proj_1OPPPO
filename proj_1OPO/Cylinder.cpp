#include "Cylinder.h"
#include "Figure.h"
#include <iostream>
#include <sstream>
#include <map>

Cylinder::Cylinder(double d, const std::string& o, double bx, double by, double h, double br) : Figure(d, o), baseX(bx), baseY(by), height(h), baseRadius(br) {}

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

    double cylinder_at;

    std::map <std::string, double> map_cylinder =
    {
        {"BaseX", baseX},
        {"BaseY", baseY},
        {"Height", height},
        {"BaseRadius", baseRadius},
        {"Density",  getDensity()}
    };

    cylinder_at = map_cylinder[keyword];

    char op;
    double value;
    if (isNumber_D(op, value, iss) && cylinder_at != 0) return Switch_haha(op, cylinder_at, value);
    else return false;
}