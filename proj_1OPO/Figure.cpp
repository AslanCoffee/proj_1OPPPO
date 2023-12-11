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

//int Figure::Key_return(std::string keyword) const
//{
//    std::map <std::string, int> mapping;
//    mapping["Radius"] = 1;
//
//    mapping["BaseX"] = 2;
//    mapping["BaseY"] = 3;
//    mapping["Height"] = 4;
//    mapping["BaseRadius"] = 5;
//    mapping["Density"] = 6;
//
//    mapping["Length1"] = 7;
//    mapping["Length2"] = 8;
//    mapping["Length3"] = 9;
//    
//    return mapping[keyword];
//
//    //switch (mapping[keyword])
//    //{
//    //case 1:
//    //    return 1;
//    //    break;
//    //case 2:
//    //    return 2;
//    //    break;
//    //case 3:
//    //    return 3;
//    //    break;
//    //case 4:
//    //    return 4;
//    //    break;
//    //case 5:
//    //    return 5;
//    //    break;
//    //case 6:
//    //    return 6;
//    //    break;
//    //case 7:
//    //    return 7;
//    //    break;
//    //case 8:
//    //    return 8;
//    //    break;
//    //case 9:
//    //    return 9;
//    //    break;
//    //default:
//    //    break;
//    //}
//}

void Figure::print() const {
    std::cout << "Owner: " << owner << ", Density: " << density << ", ";
}

bool Figure::matchesCondition(const std::string& condition) const {
    return false;
}

Figure::~Figure() {}