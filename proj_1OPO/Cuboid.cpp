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

    std::map <std::string, float> map_cuboid;
    map_cuboid["Length1"] = length1;
    map_cuboid["Length2"] = length2;
    map_cuboid["Length3"] = length3;
    map_cuboid["Density"] = getDensity();

    k_len = map_cuboid[keyword];

    //switch (Key_return(keyword))
    //{
    //case 6:
    //    k_len = getDensity();
    //    break;
    //case 7:
    //    k_len = length1;
    //    break;
    //case 8:
    //    k_len = length2;
    //    break;
    //case 9:
    //    k_len = length3;
    //    break;
    //default:
    //    return false;
    //    break;
    //}


    //if (keyword == "Length1") {
    //    k_len = length1;
    //}
    //else if (keyword == "Length2") {
    //    k_len = length2;
    //}
    //else if (keyword == "Length3") {
    //    k_len = length3;
    //}
    //else if (keyword == "Density") {
    //    k_len = getDensity();
    //}
    //else return false;

    char op;
    float value;
    iss >> op >> value;
    return Switch_haha(op, k_len, value);
}