#include <cstdlib>
#include <iostream>
#include "link.h"
using namespace std;

Link::Link()
{
    head = NULL;
}

void Link::insertFront(int data) {
    Link* tempNode = head;
    tempNode->data = data;
    tempNode->next = head;
    head           = tempNode;
}

void Link::Display()
{
    Link* tempNode = head;
    cout << "List is: "; 
    while (tempNode != NULL)
    {
        cout << tempNode->data << " ";
        tempNode = tempNode->next;
    }
    cout << "\n";
}