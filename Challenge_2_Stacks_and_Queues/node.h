#ifndef NODE_H
#define NODE_H

#pragma once

class Node{
    public:
        int data;
        Node *next;

        //Constructors
        Node(): data(0), next(nullptr) {}
        Node(int dataIn): data(dataIn), next(nullptr){}
        Node(int dataIn2, Node *nextIn): data(dataIn2), next(nextIn){}
};
#endif