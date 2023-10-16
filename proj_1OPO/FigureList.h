#pragma once
#include "FigureNode.h"

class FigureList {
private:
    FigureNode* head;
    FigureNode* tail;

public:
    FigureList();
    void push_back(Figure* figure);
    void removeIfMatches(const std::string& condition);
    void printAll() const;
    ~FigureList();
};