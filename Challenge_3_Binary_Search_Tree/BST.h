#include "node.h"
#include <ostream>

using namespace std;

#ifndef BST_H
#define BST_H

#pragma once

class BST
{
    private:
        Node* root;
        bool insert(Node *&node, int data);
        bool remove(Node *&node, int data);
        bool find(Node* node, int data);
        void inOrder(Node* node, ostream& os);
        void preOrder(Node* node, ostream& os);
        void postOrder(Node* node, ostream& os);
    public:
        BST(): root(nullptr) {}
        ~BST();
        bool insert(int data);
        bool remove(int data);
        bool find(int data);
        void inOrder(ostream& os);
        void preOrder(ostream& os);
        void postOrder(ostream& os);
};


#endif