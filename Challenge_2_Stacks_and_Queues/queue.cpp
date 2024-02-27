#include "queue.hpp"

Queue::~Queue()
{
    Node *tmp = first;
    while(tmp != nullptr)
    {
        first = first->next;
        delete tmp;
        tmp=first;
    }
    last = nullptr;
}
void Queue::push(int data)
{
    Node *tmp = new Node(data);

    if (first==nullptr) first=tmp;
    else last->next=tmp;

    last=tmp;
}
bool Queue::pop()
{
    Node *tmp = first;

    if(first == nullptr)return false; //checks if queue is empty

    first = first->next; 

    if(first == nullptr) last = nullptr;

    delete tmp;

    return true;
}
int Queue::peek(int &data)
{
    if(first == nullptr) return false;

    data = first->data;

    return true;
}
void Queue::display(std::ostream &os)
{
    Node *tmp = first;

    while (tmp != nullptr)
    {
        os << tmp->data << " ";

        tmp = tmp->next;
    }
    os << std::endl;
}