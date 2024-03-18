#include "iostream"
#include "queue.hpp"

int main()
{
    Queue Q;
    int tmp;
    Q.enqueue(5);
    Q.peek(tmp);
    std::cout << tmp << std::endl;
    Q.enqueue(33);
    Q.enqueue(1);
    Q.enqueue(7);
    Q.peek(tmp);
    std::cout << tmp << std::endl;
    Q.enqueue(33);
    Q.enqueue(12);
    Q.display( std::cout );
    Q.dequeue( );
    Q.display( std::cout );
    Q.enqueue(14);
    Q.display( std::cout );
    Q.dequeue( );
    Q.dequeue( );
    Q.display( std::cout );
    Q.dequeue( );
    Q.dequeue( );
    Q.display( std::cout );
    Q.peek(tmp);
    std::cout << tmp << std::endl;
    return 0;
}
