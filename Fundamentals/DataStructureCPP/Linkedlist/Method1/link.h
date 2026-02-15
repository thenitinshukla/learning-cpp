/* Link.h*/

#ifndef LINK_H
#define LINK_H

class Link
{
    private:
        Link* head;
    public: 
        int data;
        Link* next;
        Link();
        void insertFront(int data);
        void Display();
        ~Link();
};

#endif