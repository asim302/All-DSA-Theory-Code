// 4. Write a program to search for a value in the linked list.
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
// Head ko Inialize kr dia poori Singly list bnane ke bad
head = &node1; 
cout << "Enter Number you want to search in Link List:" << endl;
int b;
cin>>b;
node *current2 = head;
bool found= false;
while (current2 != nullptr)   // jab tak last (Null) na ho
{
    int c = current2->data;
    current2 = current2->adress;      // agle node pe move karo
     if (c == b)
     {
        cout << "Your Number is in the List:" << endl;
        found = true;
        break;
    }
    
} 
if (found != true){
            cout << "Your Number is not in the List:" << endl;
}
// For Displaying list Numbers
node *current = head;

while (current != nullptr)   // jab tak last (Null) na ho
{
   cout<<current->data<<endl;
   current = current->adress ;
    
}   

}