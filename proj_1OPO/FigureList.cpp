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

void FigureList::removeIfMatches(const std::string& condition) {
    if (head == nullptr)
        return;

    FigureNode* curr = head;
    FigureNode* prev = nullptr;

    while (!curr->figure->matchesCondition(condition)) {
        if (curr->next == head) {
            return;
        }
        prev = curr;
        curr = curr->next;
    }

    if (curr->next == head) {
        delete curr;
        head = nullptr;
    }
    else if (curr == head) {
        prev = head;
        while (prev->next != head)
            prev = prev->next;
        head = curr->next;
        prev->next = head;
        delete curr;
    }
    else {
        prev->next = curr->next;
        delete curr;
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

//FigureNode* FigureList::getTail() {
//    return tail;
//}

int FigureList::getSize() const
{
    int count = 0;
    FigureNode* current = head;
    if (head == nullptr) return 0;
    do {
        count++;
        current = current->next;
    } while (current != head);
    return count;
}