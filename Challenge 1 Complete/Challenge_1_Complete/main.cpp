#include <iostream>
#include "linkedlist.h"

using namespace std;

int main()
{
    LinkedList LL;
    LL.append(5);
    LL.append(33);
    LL.append(1);
    LL.append(7);
    LL.append(33);
    LL.append(12);
    LL.display( cout );
    std::cout << "Should = 5 33 1 7 33 12" << std::endl;
    LL.remove(33);
    LL.display( cout );
    LL.prepend(12);
    LL.display( cout );
    LL.remove(13);
    LL.display( cout );
    return 0;
}
