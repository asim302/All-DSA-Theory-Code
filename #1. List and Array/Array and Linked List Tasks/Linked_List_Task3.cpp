// 3. Write a program to delete a node from the linked list.
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

//Node 4
node node4 = node();
node4.data = 400;
node4.adress =nullptr;
// Ab node 3 ko node 4 se jor do
node3.adress = &node4;

// Head ko Inialize kr dia poori Singly list bnane ke bad
head = &node1;
// ______________________ 
cout << "List Before Deletion" << endl;
node *current2 = head;
while (current2 != nullptr)   // jab tak last (Null) na ho
{
   cout<<current2->data<<endl;
   current2 = current2->adress ;
    
}   

cout << "Do You want to Delete node from Start or from Last : s/l" << endl;
string s;
cin>>s;
if(s== "s")
{
struct  node *ptr = head;   // pointer ke sath * sirf Inialization ke waqt lgate han
// us ke bad pointer ko * ke begair hi use krte han
  free(ptr); // ptr ko free kr do 
  ptr->adress = nullptr; // aur phir ptr ke adress ko null krdo
  // Phir node ko head bnado
  head = &node2;
    
}
else if (s=="l")
{
  struct  node *temp1 = head;   // pointer ke sath * sirf Inialization ke waqt lgate han
  struct  node *temp2 = head; 
  while(temp1->adress != nullptr) // jab tb agla Ptr null na mile tb tak traversing kro
  // aur last wala node find kro
  {
     temp2 = temp1;
     temp1 = temp1->adress;   
  }
  temp2->adress = nullptr;
  free(temp1);  
  temp1 = nullptr;
   
   }

else
{
    cout << "Wrong Choice.. Try Again" << endl;

}

// For Displaying list Numbers
cout << "List After Deletion" << endl;
node *current = head;

while (current != nullptr)   // jab tak last (Null) na ho
{
   cout<<current->data<<endl;
   current = current->adress ;
    
}   

}