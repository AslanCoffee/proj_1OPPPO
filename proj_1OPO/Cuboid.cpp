#include "Cuboid.h"
#include <iostream>
#include <sstream>

Cuboid::Cuboid(double d, const std::string& o, int l1, int l2, int l3) : Figure(d, o), length1(l1), length2(l2), length3(l3) {}

void Cuboid::print() const {
    Figure::print();
    std::cout << "Length1: " << length1 << ", Length2: " << length2 << ", Length3: " << length3 << std::endl;
}

bool Cuboid::matchesCondition(const std::string& condition) const {
    std::istringstream iss(condition);
    std::string keyword;
    iss >> keyword;
    if (keyword == "Owner") {
        char op;
        std::string name;
        iss >> op >> name;
        if (name == getOwner() && op == '=') return true;
    }

    float k_len;

    if (keyword == "Length1") {
        k_len = length1;
    }
    else if (keyword == "Length2") {
        k_len = length2;
    }
    else if (keyword == "Length3") {
        k_len = length3;
    }
    else if (keyword == "Density") {
        k_len = getDensity();
    }
    else return false;

    char op;
    float value;
    iss >> op >> value;

    switch (op) {
    case '>':
        return k_len > value;
    case '<':
        return k_len < value;
    case '=':
        return k_len == value;
    default:
        return false;
    }
}