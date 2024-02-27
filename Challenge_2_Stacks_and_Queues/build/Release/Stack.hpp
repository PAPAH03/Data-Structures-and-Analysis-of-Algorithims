#include "node.hpp"
#include <ostream>

#ifndef STACK_H
#define STACK_H

#pragma once

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

    friend std::ostream &operator<<(std::ostream &os, Stack &right);

};

#endif