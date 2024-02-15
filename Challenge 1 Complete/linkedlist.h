#include "node.h"
#include <ostream>

#ifndef LINKEDLIST_H
#define LINKEDLIST_H


class LinkedList
{
private:
    Node *head ,*tail;
public:
    LinkedList(): head(nullptr),tail(nullptr) {}
    ~LinkedList();

    void append(int data);
    void prepend(int data);

    bool remove(int val);
    bool tailRemove(int val);

    void display(std::ostream &os);
    void tailDisplay(std::ostream &os);

    friend std::ostream &operator<<(std::ostream &os, LinkedList &right);
};

#endif // LINKEDLIST_H
