#include "Node.h"
#include <ostream>

#ifndef STACK_H
#define STACK_H


class Stack
{
private:
    Node *top;
public:
    Stack(): top(nullptr) {}
    ~Stack();

    void push(int data);
    bool pop();
    int peek(int &data);

    void display(std::ostream &os);

};

#endif // STACK_H
