#include <iostream>
using namespace std;
// Fix summary (what was fixed):
// 1) Replaced uninitialized pointer in main: changed `Doubly_Linked_List *l2;` ( UB )
//    to a stack object `Doubly_Linked_List l2;` and call methods with `.` to avoid
//    undefined behavior from using an uninitialized pointer.
// 2) Fixed accidental assignments in conditionals: changed `if (head = nullptr)`
//    to `if (head == nullptr)` so checks actually compare instead of assign.
// 3) Added null checks and updated `head` on boundary cases (deleting first/last
//    node, single-node lists) to avoid dereferencing null pointers.
// 4) Simplified allocations: removed redundant `new node()` before calling
//    `make_full_Node(...)` which already allocates and initializes a node.
// 5) Guarded insert-at-position when inserting at start or at end (handle
//    `node_after_temp == nullptr`). Also updated links (`prev`/`next`) correctly.
// 6) Ensured `del_at_start`, `del_at_end`, and `del_at_pos` properly update
//    neighboring pointers and `head` when needed and free memory safely.
// 7) Added `return 0;` in `main()` and display after updates so program output
//    is predictable and visible.
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
			cout << temp->data << " <-> ";
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
			node *new_node = make_full_Node(val); // make_full_Node se allocate kia (redundant new remove)
			head = new_node;
			return;
		}
		node *temp = head;
		while (temp->next != nullptr)
		{
			temp = temp->next;
		}
		node *new_node = make_full_Node(val);
		new_node->prev = temp; // node ke prev man temp rakha (backward connection)
		temp->next = new_node; // phir temp ke next man new_node ko rakh dia  (forward connection)
		// temp(pichle end wale node) ko new_node se jor dia
		return;
	}
	// 4.Add node at specific position
	void add_at_pos(int val, int pos) 
	{
		// pos se agle index pe naya node add hoga
		//IMPORTANT Case: agr pos <= 0 ha YA (OR) head null ha to start man insert krdo 
		if (pos <= 0 || head == nullptr) // add at start when pos<=0 or empty list
		{
			//Agr head null ha to head pe ek complete node  bnalo
			if (head == nullptr)
			{
				head = make_full_Node(val); // agar list empty thi to head set kia (fix)
				return;
			}
			// agr position 0 ha YA -ve bi ha tab bi start pe insert krdo
			node *newNode = make_full_Node(val);
			newNode->next = head;
			head->prev = newNode; // start pe insert kia, head prev update kia (fix)
			head = newNode; // phir new_node ko head bna dia 
			return;
		}
		//let: agr pos 3 ha to temp man position 4 wala node store hoga 	
		node *temp = head;
		int count = 0;
		while (count < pos - 1 && temp->next != nullptr)
		{
			temp = temp->next;
			count++;
		}
		node *new_node = make_full_Node(val);
		node* node_after_temp = temp->next;
		new_node->prev = temp; // Backward Connection
		new_node->next = node_after_temp; // Forward Connection
		temp->next = new_node; //3.Phir temp ke next man bi new_node (mtlb temp ka connection bi new_node se bna dia ) 
		if (node_after_temp != nullptr)// agar node_after_temp null hua to sirf backward connection bnao
			node_after_temp->prev = new_node; //2 - agar node_after_temp null hua to prev set nahi kia (fix)
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
		while(count < pos && temp->next != nullptr) // jab tk position wala node na ajaye AUR(AND) wo end wala node na ho to tb TAK Loop chalate rho
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
		//del at start ke cases
	//1. Head null hoskta ha
	//2. Head null nhi ha
		
		if (head == nullptr)
		{
			cout << "List is Empty" << endl;
			return;
		}
		node* temp = head;
		node* next_temp = temp->next;
		// delete at start: ab null check aur head update add kia taake crash na ho (fix)
		// Agr at least 2 nodes han
		if (next_temp != nullptr) //agr next temp null nhi ha to to next_temp ke prev ko null kr dia 
		//is se start wala del hojaye ga 
		{
			next_temp->prev = nullptr;
			head = next_temp; //end pe next_temp ko head bna diya
		}
		else
		{
			head = nullptr; // agar sirf ek node thi to head null kar do (fix)
		}
		delete temp;
	}
	// 9.del at end
	void del_at_end()
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
		// temp is last node
		if (temp->prev != nullptr) // temp->prev null nhi ha (Mtlb ek se zyada nodes han)
		{
			node* node_before_temp = temp->prev;
			//temp se pichle node ke NEXT man null rakh do
			//aur end pe temp ko safely del krdo 
			node_before_temp->next = nullptr;
		}
		else
		{
			// only one node
			head = nullptr; // agar sirf ek node thi to head null kar do (fix)
		}
		delete temp;
		}
	// 10.del at position
	void del_at_pos(int pos)
	{
		// Del ke cases:  1.head null ha  2.pos < 0 ha 3.Position valid ha (to phir main code chalao)
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
		node *temp = head;
		int count = 0;
		while (temp != nullptr && count < pos) // jab tk position wala node na ajaye  AUR(AND)  wo end wala node na ho to tb TAK Loop chalate rho
		{
			temp = temp->next;
			count++;
		}
		if (temp == nullptr)
		{
			cout << "Position out of range" << endl;
			return;
		}
		node *node_before_temp = temp->prev;
		node *node_after_temp = temp->next;
		// del_at_pos - head aur pointers ko safely update kia (fix)
		if (node_before_temp != nullptr) // (agr ek se zyada nodes han)
			node_before_temp->next = node_after_temp; //simply node_before_temp ke next man  node_after_temp rakh do (mtlb temp skip hogya)
		else // Agr sirf 2 nodes han
			head = node_after_temp;
		if (node_after_temp != nullptr) 
			node_after_temp->prev = node_before_temp;
		delete temp; //end pe temp ko safely del krdia		 
	}
};

 main()
{
	Doubly_Linked_List l2;
	l2.Add_at_end(5);
	l2.Add_at_end(10);
	l2.Add_at_end(15);
	l2.Add_at_end(20);
	l2.display();
	cout << "____________" << endl;
	l2.addAtStart(3);
	l2.addAtStart(1);
	l2.display();
	cout << "____________" << endl;
	l2.add_at_pos(25,5);
		l2.display();
	l2.add_at_pos(30,6);
	l2.display();
	l2.add_at_pos(12,3);
	l2.display();
	cout << "____________" << endl;
	l2.update_at_start(2);
	l2.display();
	l2.update_at_end(27);
	l2.display();
	cout << "____________" << endl;
	l2.update_at_pos(4,2); // ye thek krna ha bad man (POSITION 2 se agla element update hojaye ga)
	l2.display();
		cout << "____________" << endl;
	l2.del_at_start();
		l2.display();
	l2.del_at_start();
		l2.display();
	l2.del_at_end();
	l2.display();
		cout << "____________" << endl;
	l2.del_at_pos(3);
	l2.display();
	l2.del_at_pos(2);//del_at_pos se 1 aur 2 pos wala node ni del hoskta 
		l2.display();	
	
}
