#include "FigureList.h"
#include <iostream>
#include <fstream>
#include <sstream>

FigureList::FigureList() : head(nullptr), tail(nullptr) {}

void FigureList::push_back(Figure* figure) {
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

void FigureList::printAll() const {
    if (!head) {
        return;
    }

    FigureNode* current = head;

    do {
        current->figure->print();
        current = current->next;
    } while (current != head);
}

FigureList::~FigureList() {
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