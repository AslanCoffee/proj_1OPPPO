#include "Cuboid.h"
#include <iostream>
#include <sstream>
#include <map>

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

    static std::map <std::string, float> map_cuboid = {
        {"Length1", length1},
        {"Length2", length2},
        {"Length3", length3},
        {"Density", getDensity()}
    };
    //map_cuboid["Length1"] = length1;
    //map_cuboid["Length2"] = length2;
    //map_cuboid["Length3"] = length3;
    //map_cuboid["Density"] = getDensity();

    k_len = map_cuboid[keyword];

    char op;
    float value;
    iss >> op >> value;
    return Switch_haha(op, k_len, value);
}