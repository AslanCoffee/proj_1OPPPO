#include "FigureList.h"
#include <iostream>

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