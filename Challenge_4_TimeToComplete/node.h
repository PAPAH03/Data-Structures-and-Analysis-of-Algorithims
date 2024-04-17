#pragma once
#pragma once


#ifndef NODE_H
#define NODE_H

#pragma once

class Node
{
public:
    int data;
    Node* left;
    Node* right;
    Node* next;
    Node* prev;
    Node() : data(0), left(nullptr), right(nullptr), next(nullptr), prev(nullptr) {}
    Node(int data1) : data(data1), left(nullptr), right(nullptr), next(nullptr), prev(nullptr) {}
    Node(int data, Node* next, Node* prev) : data(data), next(next), prev(prev) {}
    int degree() const;
};

#endif


