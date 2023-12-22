#include "FigureList.h"
#include <iostream>
#include <fstream>
#include <sstream>

FigureList::FigureList() : head(nullptr), tail(nullptr), length (0) {}

void FigureList::push_back(Figure* figure) {
    FigureNode* newNode = new FigureNode(figure);

    if (!head) {
        head = newNode;
        tail = newNode;
    }
    else {
        tail->next = newNode;
        tail = tail->next;
    }
    tail->next = head;
    length++;
}

void FigureList::removeIfMatches(const std::string& condition) {
    if (head == nullptr)
        return;
    
    FigureNode* curr = head;
    FigureNode* prev = nullptr;

    for (int i = getSize(); i > 0; i--)
    {
        if (curr->figure->matchesCondition(condition)) {
            if (head == tail)
            {
                delete curr;
                head = nullptr;
                tail = nullptr;
                length--;
            }
            else if(curr == head)
            {
                head = curr->next;
                tail->next = head;
                prev = tail;
                delete curr;
                curr = head;
                length--;
            }
            else if(curr == tail)
            {
                tail = prev;
                tail->next = head;
                delete curr;
                curr = head;
                length--;
            }
            else
            {
                prev->next = curr->next;
                delete curr;
                curr = prev;
            }
            length--;
        }
        if (head != nullptr) {
            prev = curr;
            curr = curr->next;
        }
        else break;
    }

    /*while (!curr->figure->matchesCondition(condition)) {
        prev = curr;
        curr = curr->next;
    }*/

    /*
    if (curr->next == head && prev == nullptr) {
        delete curr;
        head = nullptr;
    }
    else if (curr->next == head && prev != nullptr) {
        tail = curr->next;
        prev->next = head;
        delete curr;
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
    }*/
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

int FigureList::getSize()
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