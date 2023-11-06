#include "Figure.h"
#include <iostream>
#include <sstream>

Figure::Figure(double d, const std::string& o) : density(d), owner(o) {}

double Figure::getDensity() const {
    return density;
}

std::string Figure::getOwner() const {
    return owner;
}

void Figure::print() const {
    std::cout << "Owner: " << owner << ", Density: " << density << ", ";
}

bool Figure::matchesCondition(const std::string& condition) const {
    return false;
}

Figure::~Figure() {}