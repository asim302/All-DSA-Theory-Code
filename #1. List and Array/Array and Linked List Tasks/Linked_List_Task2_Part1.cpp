//Task2 (Part 1)
//  write a program to insert a new node at the start of the linked list. 
#include <iostream>
using namespace std;
struct node  
{
    int data;
    struct node *adress; // Agle Node ka Pointer
};

 main()
{
    // head node
   struct node *head = nullptr;
      
    node node1= node();
    node1.data = 50;
    node1.adress= nullptr;
    node node2= node();
    node2.data = 100;
    node2.adress= nullptr;
// Ab node1 ko node2 ka adress de do
node1.adress = &node2;

node node3= node();
    node3.data = 200;
    node3.adress= nullptr;
// Aur last pe node2 ko node3 ka adress de dia  
node2.adress = &node3;
// Head ko Inialize kr dia poori Singly list bnane ke bad
head = &node1; 
// Now Linked List Structure
/*
  node1     node2       node3
  ______     ______     ______
 |  50  |   | 100  |   | 200  |
 |&node2|   |&node3|   |null  |
 |______|   |______|   |______| 
   node1 ==> node2 ==>  node3
*/
node *current = head;
while (current != nullptr)   // jab tak last (Null) na ho
{
    cout << current->data << " "<<endl;   // current node ka data print karo
    
    current = current->adress;      // agle node pe move karo
}   

cout << "Enter node Data You want to insert at the Start of the List: " << endl;
int a;
cin>>a;
// node jo start man add hoga
node node0 = node();
     node0.data = a;
     node0.adress= nullptr;
// ab node0 ko start man rakh ke node1 se link kr dia     
node0.adress = &node1;  
// ab node0 head bn gya ha to head ko bi Update kr dia
head = &node0;
cout << "Linked List after inserting a new node at the start" << endl;
node *current2 = head;
while (current2 != nullptr)   // jab tak last (Null) na ho
{
    cout << current2->data << " "<<endl;   // current node ka data print karo
    
    current2 = current2->adress;      // agle node pe move karo
} 

}