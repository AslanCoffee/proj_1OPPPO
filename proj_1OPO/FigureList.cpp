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