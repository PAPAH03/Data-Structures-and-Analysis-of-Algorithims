#ifndef NODE_H
#define NODE_H

#pragma once

class Node
{
    public:
        int data;
        Node* left;
        Node* right;
        Node() : data(0), left(nullptr), right(nullptr) {}
        Node(int data1) : data(data1), left(nullptr), right(nullptr) {}
        int degree() const;
};

#endif