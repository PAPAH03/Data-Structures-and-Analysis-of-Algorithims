#include "iostream"
#include "stack.hpp"

int main()
{
    Stack S;
    int tmp;
    S.push(5);
    S.peek(tmp);
    std::cout << tmp << std::endl;
    S.push(33);
    S.push(1);
    S.push(7);
    S.peek(tmp);
    std::cout << tmp << std::endl;
    S.push(33);
    S.push(12);
    S.display( std::cout );
    S.pop( );
    S.display( std::cout );
    S.push(14);
    S.display( std::cout );
    S.pop( );
    S.pop( );
    S.display( std::cout );
    S.pop( );
    S.pop( );
    S.display( std::cout );
    S.peek(tmp);
    std::cout << tmp << std::endl;
    return 0;
    rand;
}
