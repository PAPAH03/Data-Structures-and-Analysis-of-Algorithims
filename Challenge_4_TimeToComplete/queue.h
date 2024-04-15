
#include <ostream>

#ifndef STACK_H
#define STACK_H

#pragma once
struct Node{
    public:
        int data;
        Node *next;

        //Constructors
        Node(): data(0), next(nullptr) {}
        Node(int dataIn): data(dataIn), next(nullptr){}
        Node(int dataIn2, Node *nextIn): data(dataIn2), next(nextIn){}
};
class Queue
{
private:
    Node *first,*last;
public:
    Queue(): first(nullptr),last(nullptr) {}
    ~Queue();

    void enqueue(int data);
    bool dequeue();
    int peek(int &data);

    void display(std::ostream &os);

    friend std::ostream &operator<<(std::ostream &os, Queue &right);

};

#endif
