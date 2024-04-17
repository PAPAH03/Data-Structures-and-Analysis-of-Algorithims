
#include <ostream>

#ifndef STACK_H
#define STACK_H

#pragma once#pragma once
#include "node.h"
#include <ostream>

#ifndef LINKEDLIST_H
#define LINKEDLIST_H


class LinkedList
{
private:
    Node* head, * tail;
public:
    LinkedList() : head(nullptr), tail(nullptr) {}
    ~LinkedList();

    void append(int data);
    void prepend(int data);
    void appendRandomNumbers(int count, int maxRand);

    bool remove(int val);
    bool tailRemove(int val);
    bool search(int data);

    void display(std::ostream& os);
    void tailDisplay(std::ostream& os);

    friend std::ostream& operator<<(std::ostream& os, LinkedList& right);
};

#endif // LINKEDLIST_H

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
