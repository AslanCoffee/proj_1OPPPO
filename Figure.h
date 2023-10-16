#pragma once
#ifndef FIGURE_H
#define FIGURE_H
class Figure {
private:
    double density;
    string owner;
}

class Cylinder : public Figure {
private:
    int baseX, baseY, height, baseRadius;
}

class Cuboid : public Figure {
private:
    int length1, length2, length3;
}

class Sphere : public Figure {
private:
    int radius;
}
#endif