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

void Factory(string line)
{

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
            double density;
            string owner;
            if (isNumber_D(density, iss) && iss >> owner && isString(owner));
            else continue;
            string type;
            iss >> type;
            if (type == "Sphere") {
                int radius;
                if (isNumber(radius, iss)) figureList.push_back(new Sphere(density, owner, radius));
                else continue;
            }
            else if (type == "Cuboid") {
                int l1, l2, l3;
                if (isNumber(l1, iss) && isNumber(l2, iss) && isNumber(l3, iss)) figureList.push_back(new Cuboid(density, owner, l1, l2, l3));
                else continue;
            }
            else if (type == "Cylinder") {
                int bx, by, h, br;
                if (isNumber(bx, iss) && isNumber(by, iss) && isNumber(h, iss) && isNumber(br, iss)) figureList.push_back(new Cylinder(density, owner, bx, by, h, br));
                else continue;
            }
            else continue;
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