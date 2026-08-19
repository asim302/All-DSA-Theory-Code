#include <iostream>
using namespace std;
struct node
{
	int data;
	node *next;
	node *prev;
};

class Doubly_Linked_List
{
private:
	node *head;

public:
	Doubly_Linked_List()
	{
		head = nullptr;
	}
	node *make_full_Node(int val)
	{
		node *node1 = new node();
		node1->data = val;
		node1->prev = nullptr;
		node1->next = nullptr;
		return node1;
	}
	void display()
	{
		if (head == NULL)
		{
			cout << "List is empty.\n";
			return;
		}
		node *temp = head;
		while (temp != NULL)
		{
			cout << temp->data << " -> ";
			temp = temp->next;
		}
		cout << "NULL\n";
	}
	// 2.Add node at start
	void addAtStart(int value)
	{
		if (head == nullptr)
		{
			node *newNode = new node();
			newNode->data = value;
			newNode->prev = nullptr;
			newNode->next = nullptr;
			head = newNode;
			return;
		}
	//Singly Linked list man sirf ek connection (forward connection) krna prta ha 
	//but doubly list man (backward connection) bi krna prta ha
		node *temp1 = new node();
		temp1 = make_full_Node(value);
		temp1->next = head; // temp1 ke next ko current head se jor dia (forward connection)
		head->prev = temp1; // Phir head ke prev man naye start pe ane wale node ko rakh diya (backward connection)
		head = temp1;		// Phir temp1 ko naya head bana diya
		return;
	}
	// 3.Add node at end
	void Add_at_end(int val)
	{
		if (head == nullptr)
		{
		//Issue 1: pehle new_node ko memory allocate krai thi aur phir dobara make_full_Node ne bi new keyword se nayi memory allocate krad	
			//1. node *new_node = new node();
			node *new_node = make_full_Node(val);
			head = new_node;
			return;
		}
		node *temp = head;
		while (temp->next != nullptr)
		{
			temp = temp->next;
		}
		//temp mn last node ajaye ga
		node *new_node = new node();
		new_node = make_full_Node(val);
		new_node->prev = temp; // node ke prev man temp rakha (backward connection)
		temp->next = new_node; // phir temp ke next man new_node ko rakh dia  (forward connection)
		// temp(pichle end wale node) ko new_node se jor dia
		return;
	}
	// 4.Add node at specific position
	void add_at_pos(int val, int pos) 
	{
		// pos se agle index pe naya node add hoga
		if (head == nullptr || pos<= 0) // agr head null ha YA(OR)  pso <= 0 ha
		{
		//Yhan bi same issue (1) tha
			node *new_node = make_full_Node(val);
			head = new_node;
			return;
		}
		node *temp =head;
		int count = 0;
		while(count < pos - 1 && temp->next != nullptr) // jab tk count, (pos - 1) se bra na ajaye AUR(AND) wo end wala node na ho to tb TAK Loop chalate rho
		{
		temp= temp->next;	
		count++;
		}
		node *new_node = new node();
		node* node_after_temp = temp->next; //node_after_temp man temp se agla node ajaye ga
			new_node = make_full_Node(val);
			new_node->prev = temp;// backward connection
			new_node->next= temp->next; // forward connection
			//ab temp aur temp.next man bi new_node ko rakho
			temp->next = new_node; //1
			node_after_temp->prev = new_node; //2
		return ;	
			
	}
	// 5.update at start
	void update_at_start(int val)
	{
		if (head == nullptr)
		{
			cout << "List is Empty" << endl;
			return;
		}
		head->data = val;
		return;
	}
	// 6.update at end
	void update_at_end(int val)
	{
		if (head == nullptr)
		{
			cout << "List is Empty" << endl;
			return;
		}
		node *temp = head;
		while (temp->next != nullptr)
		{
			temp = temp->next;
		}
		temp->data = val;
	}
	// 7.update at position
	void update_at_pos(int val,int pos)
	{
		//2 Cases : 1.pos < 0 ha 2. head null ha
		if (head == nullptr)
		{
			cout << "List is Empty" << endl;
			return;
		}
		if (pos < 0)
		{
			cout << "Invalid Position" << endl;
			return;
		}
		node *temp =head;
		int count = 0;
		while(count < pos && temp->next != nullptr) // jab tk position se pichla node na ajaye AUR(AND) wo end wala node na ho to tb TAK Loop chalate rho
		{
		temp= temp->next;	
		count++;
		}
		if (temp == nullptr)
		{
			cout << "Position out of range" << endl;
			return;
		}
		temp->data = val;
	}
	// 8.del at start
	void del_at_start()
	{
		if (head == nullptr)
		{
			cout << "List is Empty" << endl;
			return;
		}
		node* temp = head;
		node* next_temp = temp->next;
		next_temp->prev = nullptr;
		head = next_temp;
		delete temp;
	}
	// 9.del at end
	void del_at_end()
	{
		if (head = nullptr)
		{
			cout << "List is Empty" << endl;
			return;
		}
		node *temp = head;
		while (temp->next != nullptr)
		{
			temp = temp->next;
		}
		node* end_node = temp;
		node* second_last_Node = temp->prev;
		second_last_Node->next = nullptr; //second_last_Node ko end node bna diya
		delete end_node;// phir pichle edn node ko del kr dia	
		}
	// 10.del at position
	void del_at_pos(int pos)
	{
		if (head = nullptr)
		{
			cout << "List is Empty" << endl;
			return;
		}
		if (pos < 0)
		{
			cout << "Invalid Position" << endl;
			return;
		}
		node *temp =head;
		int count = 0;
		while(count < pos -1 && temp->next != nullptr) // jab tk count < pos -1 AUR(AND) wo end wala node na ho to tb TAK Loop chalate rho
		{
		temp= temp->next;	
		count++;
		}
		node *node_before_temp = temp->prev;
		node *node_after_temp = temp->next;
		node* node_to_delete = temp;
		
		node_before_temp->next = node_to_delete->next; // forward
		node_after_temp->prev = node_to_delete->prev;  // backward
	//ab connections hogye han
	//temp delete kr do
	delete temp;			 
	}
};

main()
{
	/*
1) Replaced uninitialized pointer in main: changed `Doubly_Linked_List *l2;` ( UB )
   to a stack object `Doubly_Linked_List l2;` and call methods with `.` to avoid
   undefined behavior from using an uninitialized pointer.
	*/
	Doubly_Linked_List l2;
	l2.Add_at_end(5);
	l2.Add_at_end(10);
	l2.Add_at_end(15);
	l2.Add_at_end(20);
	l2.display();
	cout << "____________" << endl;
	l2.addAtStart(3);
	
		cout << "____________" << endl;
l2.add_at_pos(25,5);
l2.add_at_pos(30,6);
	l2.display();
	cout << "____________" << endl;
	l2.update_at_start(2);
	l2.display();
l2.update_at_end(27);
	l2.display();
	cout << "____________" << endl;
l2.update_at_pos(4,2);
	
	
}
