#define _CRTDBG_MAP_ALLOC
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "Figure.h"
#include "FigureList.h"
#include "Cuboid.h"
#include "Cylinder.h"
#include "FigureNode.h"
#include "Sphere.h"
#include <stdlib.h>
#include <crtdbg.h>

using namespace std;

enum string_code {
    Cuboid_,
    Sphere_,
    Cylinder_
};

string_code hashit(string const& inString)
{
    if (inString == "Cuboid") return Cuboid_;
    if (inString == "Sphere") return Sphere_;
    if (inString == "Cylinder") return Cylinder_;
}

bool isString(const std::string& input) {
    int y = 0, size;
    size = input.length();
    for (char c : input) {
        if (!isdigit(c)) {
            y++;
        }
    }
    return size == y;
}

bool isNumber(int& x, istringstream& iss)
{
    iss >> x;
    if (iss.fail() && !isspace(iss.peek())) {
        return 0;
    }
    else {
        return 1;
    }
}

bool isNumber_D(double& x, istringstream& iss)
{
    iss >> x;
    if (iss.fail() && !isspace(iss.peek())) {
        return 0;
    }
    else {
        return 1;
    }
}

Figure* Factory(istringstream& iss)
{
    double density;
    string owner;
    if (isNumber_D(density, iss) && iss >> owner && isString(owner));
    string type;
    iss >> type;
    switch (hashit(type))
    {
    case Cuboid_:
        int l1, l2, l3;
        if (isNumber(l1, iss) && isNumber(l2, iss) && isNumber(l3, iss)) return new Cuboid(density, owner, l1, l2, l3);
        else break;
        break;
    case Cylinder_:
        int bx, by, h, br;
        if (isNumber(bx, iss) && isNumber(by, iss) && isNumber(h, iss) && isNumber(br, iss)) return new Cylinder(density, owner, bx, by, h, br);
        else break;
        break;
    case Sphere_:
        int radius;
        if (isNumber(radius, iss)) return new Sphere(density, owner, radius);
        else break;
        break;
    default:
        break;
    }
}

int main() {
    FigureList figureList;
    ifstream inputFile("input.txt");
    if (!inputFile.is_open()) {
        cerr << "Unable to open input.txt" << endl;
        return 1;
    }

    string line;
    while (getline(inputFile, line)) {

        istringstream iss(line);
        string command;
        iss >> command;

        if (command == "ADD") {
            figureList.push_back(Factory(iss));
        }
        else if (command == "REM") {
            string condition;
            getline(iss, condition);
            figureList.removeIfMatches(condition);
        }
        else if (command == "PRINT") {
            figureList.printAll();
            cout << "-----------------" << endl;
        }
        else {
            cerr << "Command Error: " << command << endl;
        }
    }
    _CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_DEBUG);
    _CrtDumpMemoryLeaks();
    return 0;
}