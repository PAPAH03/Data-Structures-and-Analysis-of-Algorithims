#include "BST.h"
#include <ostream>

using namespace std;

BST::~BST()
{
    while(root != nullptr)
    {
        remove(root,root->data);
    }
}

bool BST::insert(Node *&node, int data)
{
    if (node == nullptr) {
        node = new Node(data);
        return true; }
    if (data < node->data)
        return insert(node->left, data);
    if (data > node->data)
        return insert(node->right, data);
    return false;
}

bool BST::remove(Node *&node, int data)
{
   
}

bool BST::find(Node* node, int data)
{
    if (node == nullptr){
        return false;
    }
    if (node->data == data){
        return true;
    }
    if (data > node->data){
        node = node->right;
        return find(node, data);
    }
    if(data < node->data){
        node = node->left;
        return find(node, data);
    }
    //sanity check
    return false;

}

void BST::postOrder(Node* node, ostream& os)
{
    if (node == nullptr) return;
    postOrder(node->left, os);
    postOrder(node->right, os);
    os << node->data << " ";
}

void BST::preOrder(Node* node, ostream& os)
{
    if (node == nullptr) return;
    os << node->data << " ";
    preOrder(node->left, os);
    preOrder(node->right, os);
}

void BST::inOrder(Node* node, ostream& os)
{
    if (node == nullptr) return;
    inOrder(node->left, os);
    os << node->data << " ";
    inOrder(node->right, os);
}

int Node::degree() const
{
    int degree = 0;
    if(this->left != nullptr){
        degree ++;
    }
    if(this->right != nullptr){
        degree ++;
    }
    return degree;
}


//public functions

bool BST::insert(int data)
{
    return insert(root,data);
}
bool BST::remove(int data)
{
    return remove(root,data);
}
bool BST::find(int data)
{
    return find(root,data);
}
void BST::inOrder(ostream& os)
{
    inOrder(root,os);
}
void BST::preOrder(ostream& os)
{
    preOrder(root,os);
}
void BST::postOrder(ostream& os)
{
    postOrder(root,os);
}