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

    std::map <std::string, float> map_cylinder;
    map_cylinder["BaseX"] = baseX;
    map_cylinder["BaseY"] = baseY;
    map_cylinder["Height"] = height;
    map_cylinder["BaseRadius"] = baseRadius;
    map_cylinder["Density"] = getDensity();

    cylinder_at = map_cylinder[keyword];

    //switch (Key_return(keyword))
    //{
    //case 2:
    //    cylinder_at = baseX;
    //    break;
    //case 3:
    //    cylinder_at = baseY;
    //    break;
    //case 4:
    //    cylinder_at = height;
    //    break;
    //case 5:
    //    cylinder_at = baseRadius;
    //    break;
    //case 6:
    //    cylinder_at = getDensity();
    //    break;
    //default:
    //    return false;
    //    break;
    //}


    /*cylinder_at = Key_return(keyword);
    * 
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
    else return false;*/

    char op;
    float value;
    iss >> op >> value;
    return Switch_haha(op, cylinder_at, value);
    //switch (op) {
    //case '>':
    //    return cylinder_at > value;
    //case '<':
    //    return cylinder_at < value;
    //case '=':
    //    return cylinder_at == value;
    //default:
    //    return false;
    //}
}