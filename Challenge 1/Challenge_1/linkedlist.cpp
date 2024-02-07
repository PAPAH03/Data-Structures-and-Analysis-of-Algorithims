#include "linkedlist.h"


LinkedList::~LinkedList()
{
    Node *tmp = head;

    while (tmp!=nullptr)
    {
        head=head->next;

        delete tmp;

        tmp = head;
    }

    tail = nullptr;
}

void LinkedList::append(int data)
{
    Node *tmp = new Node(data);

    if(head == nullptr)
    {
        head = tmp;
        tail = head;
    }
    else{
        tail->next = tmp;
        }
        tail = tmp;
}
void LinkedList::prepend(int data)
{
    Node *tmp = new Node(data);
    if (head == nullptr)
    {
        tail = tmp;
    }

    tmp->next = head;

    head = tmp;
}


void LinkedList::display(std::ostream &os)
{
        Node *tmp = head;

        while (tmp != nullptr)
        {
            os << tmp->data << std::endl;

            tmp = tmp->next;
        }
}

bool LinkedList::remove(int data)
{
    Node *tmp = head;
    Node *prev = nullptr;

        while(tmp != nullptr)
    {
        if (tmp-> data == data)
        {
            if(tmp == head)
            {
                head = tmp->next;
            }
            else{
                prev->next = tmp->next;
            }
            if(tmp==tail)
            {
                tail = prev;
            }

            delete tmp;

            return true;
        }
        prev = tmp;
        tmp = tmp->next;
    }
    return false;
}

std::ostream &operator<<(std::ostream &os, LinkedList &right)
{
    right.display(os);

    return os;
}


