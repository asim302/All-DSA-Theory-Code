// 5. Write a program to reverse the linked list
#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *adress;
};

int main()
{
    // Create Linked List 
    node *head = nullptr;

    node node1;
    node1.data = 50;
    node1.adress = nullptr;

    node node2;
    node2.data = 100;
    node2.adress = nullptr;

    node1.adress = &node2;

    node node3;
    node3.data = 200;
    node3.adress = nullptr;

    node2.adress = &node3;

    head = &node1;

    cout << "Original Linked List: " << endl;
    node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->adress;
    }

    node *prev = nullptr;      
    node *current = head;      
    node *next = nullptr;     

    while (current != nullptr)
    {
        next = current->adress;   

        current->adress = prev;   

        prev = current;           

        current = next;       
        }

    head = prev;   

    cout << endl << "Reversed Linked List: " << endl;

    node *temp2 = head;
    while (temp2 != nullptr)
    {
        cout << temp2->data << " ";
        temp2 = temp2->adress;
    }
}
