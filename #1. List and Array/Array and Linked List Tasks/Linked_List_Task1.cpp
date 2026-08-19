/*
Linked List :
1. Write a program to create a singly linked list and display its elements.
5. Write a program to reverse the linked list.
*/
#include <iostream>
using namespace std;
struct node  
{/*
    // Single Linked List
    is man sirf 2 Cheezen hoti han
    1.data 
    2. aur agle node ka adress
   */ 
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
node2.adress = &node3;
// Head ko Inialize kr dia poori Singly list bnane ke bad
head = &node1; 
// Now Linked List Structure
/*
  node1     node2      node3
  ______     ______     ______
 |  50  |   | 100  |   | 200  |
 |&node2|   |&node3|   |null  |
 |______|   |______|   |______| 
   node1 ==> node2 ==>  node3
*/

// Print Each Node
node *current = head;
while (current != nullptr)   // jab tak last (Null) na ho
{
    cout << current->data << " "<<endl;   // current node ka data print karo
    
    current = current->adress;      // agle node pe move karo
} 

/*
// Dynamic Node Bnana (DSA man yehi thek rehta ha)
node *node1 = new node;   // memory ban gai
// Is trah node heap man bnta ha aur memory destroy nhi hoti
node1->data = 50;         // data fill
node1->adress = nullptr;  // next NULL
//👉 Yahan -> isliye use kiya kyunke node1 pointer hai
*/
}