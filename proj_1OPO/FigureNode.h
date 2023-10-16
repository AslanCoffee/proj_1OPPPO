#pragma once
#include "Figure.h"

class FigureNode {
public:
    Figure* figure;
    FigureNode* next;

    FigureNode(Figure* f);
};