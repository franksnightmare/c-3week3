#include "main.h"

int main()
{
    ShlInserter obj1(2);
    ShlInserter	obj2(1);
    obj1 <<= obj2;
    std::cout << obj1.Data() << "\n";
}
