#include <cstdlib>
#include <iostream>
#include "link.h"

int main()
{
    Link* head = new Link();
    std::cout << " How many numers? " << std::endl;
    int n, x; 
    std::cin >> n; 
    for ( int i = 0; i < n; i++)
    {
        std::cout << "Enter the number \n ";
        std::cin >>  x;
        head->insertFront(x);
        head->Display();
    }
    return 0;
}