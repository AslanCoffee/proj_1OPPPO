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

using namespace std;

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
            iss >> density >> owner;

            string type;
            iss >> type;
            if (type == "Sphere") {
                int radius;
                iss >> radius;
                figureList.push_back(new Sphere(density, owner, radius));
            }
            else if (type == "Cuboid") {
                int l1, l2, l3;
                iss >> l1 >> l2 >> l3;
                figureList.push_back(new Cuboid(density, owner, l1, l2, l3));
            }
            else if (type == "Cylinder") {
                int bx, by, h, br;
                iss >> bx >> by >> h >> br;
                figureList.push_back(new Cylinder(density, owner, bx, by, h, br));
            }
            else {
                cerr << "ADD Error: " << line << endl;
            }
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

    return 0;
}
//удаление файла из репозиторрия git filterbranch, удалить каталог out
//разбить по файлам, отдельано список, фигуры, отдельно main, remove if match, функция удаления спереди и сзади как стандартную back и front
//valgrint динамический оптимизатор кода, чтобы перестал течь память.
//отедльное коммит в отедльную ветку.