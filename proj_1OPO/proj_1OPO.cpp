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

class Figure {
private:
    double density;
    string owner;
public:

    double getDensity() const {
        return density;
    }

    string getOwner() const {
        return owner;
    }

    Figure(double d, const string& o) : density(d), owner(o) {}

    virtual void print() const {
        cout << "Owner: " << owner << ", Density: " << density << ", ";
    }

    virtual bool matchesCondition(const string& condition) const {
        return false;
    }

    virtual ~Figure() {}
};

class FigureNode {
public:
    Figure* figure;
    FigureNode* next;

    FigureNode(Figure* f) : figure(f), next(nullptr) {}
};

class Sphere : public Figure {
private:
    int radius;
public:

    Sphere(double d, const string& o, int r) : Figure(d, o), radius(r) {}

    void print() const override {
        Figure::print();
        cout << "Radius: " << radius << endl;
    }

    bool matchesCondition(const string& condition) const override {
        istringstream iss(condition);
        string keyword;
        iss >> keyword;

        if (keyword == "Owner") {
            char op;
            string name;
            iss >> op >> name;
            if (name == getOwner() && op == '=') return 1;
        }

        float atribute;
        if (keyword == "Density") atribute = getDensity();
        else if (keyword == "Radius")atribute = radius;
        else return false;

        char op;
        float value;
        iss >> op >> value;

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
};

class Cuboid : public Figure {
private:
    int length1, length2, length3;
public:

    Cuboid(double d, const string& o, int l1, int l2, int l3) : Figure(d, o), length1(l1), length2(l2), length3(l3) {}

    void print() const override {
        Figure::print();
        cout << "Length1: " << length1 << ", Length2: " << length2 << ", Length3: " << length3 << endl;
    }

    bool matchesCondition(const string& condition) const override {
        istringstream iss(condition);
        string keyword;
        iss >> keyword;
        if (keyword == "Owner") {
            char op;
            string name;
            iss >> op >> name;
            if (name == getOwner() && op == '=') return 1;
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
};

class Cylinder : public Figure {
private:
    int baseX, baseY, height, baseRadius;
public:

    Cylinder(double d, const string& o, int bx, int by, int h, int br) : Figure(d, o), baseX(bx), baseY(by), height(h), baseRadius(br) {}

    void print() const override {
        Figure::print();
        cout << "BaseX: " << baseX << ", BaseY: " << baseY << ", Height: " << height << ", BaseRadius: " << baseRadius << endl;
    }



    bool matchesCondition(const string& condition) const override {
        istringstream iss(condition);
        string keyword;
        iss >> keyword;
        if (keyword == "Owner") {
            char op;
            string name;
            iss >> op >> name;
            if (name == getOwner() && op == '=') return 1;
        }

        float Cylinder_at;

        if (keyword == "BaseX") {
            Cylinder_at = baseX;
        }
        else if (keyword == "BaseY") {
            Cylinder_at = baseY;
        }
        else if (keyword == "Height") {
            Cylinder_at = height;
        }
        else if (keyword == "BaseRadius") {
            Cylinder_at = baseRadius;
        }
        else if (keyword == "Density") {
            Cylinder_at = getDensity();
        }
        else return false;


        char op;
        float value;
        iss >> op >> value;

        switch (op) {
        case '>':
            return Cylinder_at > value;
        case '<':
            return Cylinder_at < value;
        case '=':
            return Cylinder_at == value;
        default:
            return false;
        }
    }
};

class FigureList {
private:
    FigureNode* head;
    FigureNode* tail;
public:

    FigureList() : head(nullptr), tail(nullptr) {}

    void push_back(Figure* figure) {
        FigureNode* newNode = new FigureNode(figure);

        if (!head) {
            head = newNode;
            tail = newNode;
            tail->next = head;
        }
        else {
            tail->next = newNode;
            tail = newNode;
            tail->next = head;
        }
    }

    void removeIfMatches(const string& condition) {
        if (!head) {
            return;
        }

        FigureNode* current = head;
        FigureNode* prev = nullptr;
        FigureNode* next;

        do {
            next = current->next;

            if (current->figure->matchesCondition(condition)) {
                if (current == head) {
                    head = next;
                    if (head == current) {
                        head = nullptr;
                        tail = nullptr;
                    }
                    else {
                        tail->next = head;
                    }
                }
                else if (current == tail) {
                    tail = prev;
                    tail->next = head;
                }
                else {
                    prev->next = next;
                }
                delete current;
            }

            if (head == nullptr) {
                break;
            }

            prev = current;
            current = next;
        } while (current != head);
    }

    void printAll() const {
        if (!head) {
            return;
        }

        FigureNode* current = head;

        do {
            current->figure->print();
            current = current->next;
        } while (current != head);
    }

    ~FigureList() {
        if (!head) {
            return;
        }

        FigureNode* current = head;

        do {
            FigureNode* next = current->next;
            delete current;
            current = next;
        } while (current != head);
    }
};

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