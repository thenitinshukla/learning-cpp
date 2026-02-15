#include <iostream>
using namespace std;

class Node
{
    private:
        Node* head;
    public: 
        int data;
        Node* next;
        Node(){
            head = NULL;
        }
        void insertFront(int data);
        void deleteFront();
        void Display();
};

void Node::insertFront(int data)
{
    Node* temp = new Node();
    temp->data = data;
    temp->next = head;
    head = temp;
}

void Node::deleteFront()
{
    Node* temp = head;
    if( temp == NULL) {
        cout << "Linked List Empty, nothing to delete" ; 
        return;
    }
    head = head->next;
    cout << "Value deleted: " << temp->data << endl;
    free(temp);
} 

void Node::Display()
{
    Node* temp = head;
    cout << "List is: "; 
    while (head != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
}

int main()
{
    Node* linked_list = new Node();
    cout << " How many numers? " << endl;
    int n, x; 
    cin >> n; 
    for ( int i = 0; i < n; i++)
    {
        cout << "Enter the number \n ";
        cin >>  x;
        linked_list->insertFront(x);
        linked_list->Display();
    }
    linked_list->deleteFront();
    linked_list->Display();
    return 0;
}