#include <iostream>
using namespace std;
class node
{
public:	
int data ;
node* next;
node(int val)
{
	data = val;
	next = nullptr;
}	
};
class Queue_by_linked_list
{
	
	node* head;//front
	node* back;//back
public:
Queue_by_linked_list()
{
head = nullptr;
back = nullptr;	
}
bool is_empty()
{
	if(head == nullptr)
	{
	 return  true;
	}
	return false;
}
void enqueue(int val)
{
 node* new_node = new node(val); //ek complete node bn gya
//Ab ise queue man dal den ge
if(is_empty())
{
head = back = new_node;
}
else{
	back->next = new_node; //back ke next man new_node ko rakh do
	//bcz back pe already element ha 
	back = new_node; //phir back ko ek step age shift kr dia
//ab new_node BACK ko point kre ga 	
}
}
void dequeue()
{
	if(is_empty())
	{
		cout << "Queue is Empty" << endl;
		return ;
	}
	node* temp = head;
	node* next =  head->next;
	delete temp;
	head = next;
}

int front() 
{
	if(is_empty())
	{
		cout << "Queue is Empty" << endl;
		return -1;
	}
	return head->data;
}
void get_front() 
{
	if(is_empty())
	{
		cout << "Queue is Empty" << endl;
		return ;
	}
cout << "Front Element" << endl;
cout << head->data << endl;
}
void display()
{
	node* temp =  head;
	while(temp!=nullptr){
cout <<temp->data<< " " << endl;
temp = temp->next;
	}
}
};
 main()
{
	Queue_by_linked_list q1;
	q1.dequeue();
	q1.is_empty(); 
	//NOTE: Agr hm function man return keyword se kuch output len to wo value print ni hoti 
	//us function ki returned value ko manually cout se print krna prta ha
	q1.enqueue(2);
	q1.enqueue(5);
	q1.enqueue(7);
	q1.enqueue(9);
	cout << q1.front() << endl;
	cout << "___________" << endl;
	q1.display();
	cout << "___________" << endl;
q1.is_empty();
q1.dequeue();
cout << q1.front() << endl;
	cout << "___________" << endl;
q1.display();
	cout << "___________" << endl;
q1.dequeue();
q1.get_front();
	
}