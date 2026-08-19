#include <iostream>
using namespace std;

struct  node
{
	int data;
	node* next;
};


class Stack_by_list
{
public:
node* top; //head of Linked List
Stack_by_list()
{
	top = nullptr;
}
node* create_full_node(int val)
{
	node* node1 = new node();
	node1->data = val;
	node1->next= nullptr;
return  node1;
}
void push(int val)
{
	if (top == nullptr)
		{
			node* node1 = create_full_node(val);
			top = node1;
			return;
		}
	node* node2;
	node2 = create_full_node(val);	
	node2->next= top; //node2 ke next mn pichli top rakh di (mtlb naye node ko purani list se jod diya)
	//node2 ko start pe rakh ke list se link kr dia 
	top = node2;//phir node2 ko top bnadiya	
}
void pop()
{
if (top == nullptr)
		{
			cout << "Linked List is Empty" << endl;
			return;
		}
		cout << top->data << endl;	
node* temp = top;
top = temp->next; //top ko age shift kr diya
delete temp;
}
void get_top() //Error: Function aur variable ka name same tha
{
	cout << "Top Element" << endl;
cout << top->data << endl;
}
void display()
{

if (top == nullptr)
		{
			cout << "Linked List is Empty" << endl;
			return;
		}
node* temp = top;
while (temp != nullptr)
{
	cout <<temp->data << " ";
	temp = temp->next;
	
}
cout<< endl;

}
};
 main() {
		Stack_by_list s1;
		cout << "Stack s1" << endl;
	s1.push(5);
	s1.push(10);
	s1.push(15);
	s1.push(20);
	s1.display();
			Stack_by_list s2;

		cout << "Stack s2" << endl;
	s2.push(1);
	s2.push(3);
	s2.push(5);
	s2.push(7);
	s2.push(9);
	s2.display();
	s2.pop();
	s2.pop();
	cout << "__________________" << endl;
	
}