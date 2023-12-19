#include "Figure.h"
#include "FigureNode.h"
#include "FigureList.h"
#include "Sphere.h"
#include <iostream>
#include <string>
#include <sstream>
#include <map>

Figure::Figure(double d, const std::string& o) : density(d), owner(o) {}

double Figure::getDensity() const {
    return density;
}

std::string Figure::getOwner() const {
    return owner;
}


float Figure::Switch_haha(char op, double atribute, double value) const
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

bool isop(char op) {
    if (op == '=' || op == '<' || op == '>') return 1;
    else return false;
}

bool Figure::isNumber_D(char& op, double& x, std::istringstream& iss) const
{
    iss >> op >> x;
    if (iss.fail() && !isspace(iss.peek()) && !isop(op)) {
        return 0;
    }
    else {
        return 1;
    }
}

void Figure::print() const {
    std::cout << "Owner: " << owner << ", Density: " << density << ", ";
}

bool Figure::matchesCondition(const std::string& condition) const {
    return false;
}

Figure::~Figure() {}