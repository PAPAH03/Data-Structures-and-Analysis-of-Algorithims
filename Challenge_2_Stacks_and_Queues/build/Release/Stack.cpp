#include "stack.hpp"

Stack::~Stack()
{
    Node *tmp = top;
    while(tmp != nullptr)
    {
        top = top->next;
        delete tmp;
        tmp=top;
    }
}
void Stack::push(int data)
{
    Node *tmp = new Node(data);

    tmp->next = top;
    top = tmp;
}
bool Stack::pop()
{
    Node *tmp = top;

    if(top == nullptr){return false;}

    top = top->next;
    delete tmp;

    return true;
}
int Stack::peek(int &data)
{
    if(top == nullptr) return false;

    data = top->data;

    return true;
}
void Stack::display(std::ostream &os)
{
    Node *tmp = top;

    while (tmp != nullptr)
    {
        os << tmp->data << " ";

        tmp = tmp->next;
    }
    os << std::endl;
}