#include "Figure.h"
#include <iostream>
#include <sstream>

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