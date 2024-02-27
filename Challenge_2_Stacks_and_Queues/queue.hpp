#include "node.hpp"
#include <ostream>

#ifndef STACK_H
#define STACK_H

#pragma once

class Queue
{
private:
    Node *first,*last;
public:
    Queue(): first(nullptr),last(nullptr) {}
    ~Queue();

    void push(int data);
    bool pop();
    int peek(int &data);

    void display(std::ostream &os);

    friend std::ostream &operator<<(std::ostream &os, Queue &right);

};

#endif