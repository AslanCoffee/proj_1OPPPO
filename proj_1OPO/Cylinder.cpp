#include "Cylinder.h"
#include <iostream>
#include <sstream>
#include <map>

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

    static std::map <std::string, float> map_cylinder =
    {
        {"BaseX", baseX},
        {"BaseY", baseY},
        {"Height", height},
        {"BaseRadius", baseRadius},
        {"Density",  getDensity()}
    };
    //map_cylinder["BaseX"] = baseX;
    //map_cylinder["BaseY"] = baseY;
    //map_cylinder["Height"] = height;
    //map_cylinder["BaseRadius"] = baseRadius;
    //map_cylinder["Density"] = getDensity();

    cylinder_at = map_cylinder[keyword];

    char op;
    float value;
    iss >> op >> value;
    return Switch_haha(op, cylinder_at, value);
}