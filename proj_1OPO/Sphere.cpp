#include "Sphere.h"
#include <iostream>
#include <sstream>
#include <map>

Sphere::Sphere(double d, const std::string& o, int r) : Figure(d, o), radius(r) {}

void Sphere::print() const {
    Figure::print();
    std::cout << "Radius: " << radius << std::endl;
}

bool Sphere::matchesCondition(const std::string& condition) const {
    std::istringstream iss(condition);
    std::string keyword;
    iss >> keyword;

    if (keyword == "Owner") {
        char op;
        std::string name;
        iss >> op >> name;
        if (name == getOwner() && op == '=') return 1;
    }

    float atribute;

    std::map <std::string, float> map_sphere;
    map_sphere["Radius"] = radius;
    map_sphere["Density"] = getDensity();
    atribute = map_sphere[keyword];

    //switch (Key_return(keyword))
    //{
    //case 1:
    //    atribute = radius;
    //    break;
    //case 6:
    //    atribute = getDensity();
    //    break;
    //default:
    //    return false;
    //    break;
    //}

    //if (keyword == "Density") atribute = getDensity();
    //else if (keyword == "Radius")atribute = radius;
    //else return false;

    char op;
    float value;
    iss >> op >> value;

    return Switch_haha(op, atribute, value);
}