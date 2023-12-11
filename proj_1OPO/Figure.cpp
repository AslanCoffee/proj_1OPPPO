#include "Figure.h"
#include "FigureNode.h"
#include "FigureList.h"
#include "Sphere.h"
#include <iostream>
#include <sstream>
#include <map>

Figure::Figure(double d, const std::string& o) : density(d), owner(o) {}

double Figure::getDensity() const {
    return density;
}

std::string Figure::getOwner() const {
    return owner;
}


float Figure::Switch_haha(char op, float atribute, float value) const
{
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

void Figure::print() const {
    std::cout << "Owner: " << owner << ", Density: " << density << ", ";
}

bool Figure::matchesCondition(const std::string& condition) const {
    return false;
}

Figure::~Figure() {}