#include "Sphere.h"
#include <iostream>
#include <sstream>

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
    if (keyword == "Density") atribute = getDensity();
    else if (keyword == "Radius")atribute = radius;
    else return false;

    char op;
    float value;
    iss >> op >> value;

    switch (op) {
    case '>':
        return atribute > value;
    case '<':
        return atribute < value;
    case '=':
        return atribute == value;
    default:
        return false;
    }
}