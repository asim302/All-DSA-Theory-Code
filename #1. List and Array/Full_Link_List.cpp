#include <iostream>
using namespace std;

struct node
{
	int data;
	node *next;
};
class Linked_list
{
private:
	node *head;

public:
	Linked_list()
	{
		head = nullptr;
	}

	node *new_full_node(int val)
	{
		node *node1 = new node(); // naya node bnane ke liye hamesha new keyword use kro
		// bcz new se hi new memory allocate hoti ha aur naya structure bnta ha
		node1->data = val;
		node1->next = nullptr;
		return node1;
	}
	void display()
	{
		if (head == nullptr)
		{
			cout << "Linked List is Empty" << endl;
			return;
		}
		node *temp = head;
		// Fix: iterate until temp is nullptr so the last node's data is printed as well
		while (temp != nullptr)
		{
			cout << temp->data;
			if (temp->next != nullptr)
				cout << "->";
			temp = temp->next;
		}
		cout << "->null" << endl;
	}

	void add_at_start(int data)
	{
		if (head == nullptr)
		{
			// Pehle memory allocate krke node structure bnao
			node *New_full_Node1 = new node();
			New_full_Node1->data = data;
			New_full_Node1->next = nullptr;
			head = New_full_Node1;
			return;
			// Alternative Method
			/*
			node* New_full_Node2 = new node();
			New_full_Node2 = new_full_node(data);
				head = New_full_Node2;
			*/
		}
		node *temp1 = new node();
		temp1->data = data; // temp1 node bna kar us man data rakha
		temp1->next = head; // phir temp1 ke next man current head store kra dia (Mtlb temp1 man ka connection head se kr dia)
		head = temp1;		// end pe head man bi temp1 rakh dia
	}
	void add_node_atEnd(int data)
	{
		if (head == nullptr)
		{
			// Pehle memory allocate krke node structure bnao
			node *New_full_Node1 = new node();
			New_full_Node1->data = data;
			New_full_Node1->next = nullptr;
			head = New_full_Node1;
			return;
		}
		node *temp = head;
		while (temp->next != nullptr)
		{
			temp = temp->next;
			// temp->next;
		}
		node *end_node = new node();
		end_node->data = data;
		end_node->next = nullptr;
		temp->next = end_node;
	}

	void add_at_position(int val, int pos)
	{
		// Fix: treat pos as 0-based index. If pos==0 insert at start without losing list.
		if (pos <= 0 || head == nullptr)
		{
			node *node1 = new_full_node(val);
			node1->next = head; // connect to existing list (may be nullptr)
			head = node1;
			return;
		}
		node *temp = head;
		int count = 0; 
		// Move temp to the node at index pos-1 (or last node if pos is beyond length)
		while (count < pos - 1 && temp->next != nullptr)
		{
			temp = temp->next;
			count++;
		}
		node *node2 = new_full_node(val);
		node2->next = temp->next; // insert after temp
		temp->next = node2;
	}

	void update_at_start(int data)
	{
		if (head == nullptr)
		{
			// Pehle memory allocate krke node structure bnao
			node *New_full_Node1 = new node();
			New_full_Node1->data = data;
			New_full_Node1->next = nullptr;
			head = New_full_Node1;
			return;
		}
		head->data = data; // header ka data replace kr dia
	}
	void update_at_end(int data)
	{
		if (head == nullptr)
		{
			// Pehle memory allocate krke node structure bnao
			node *New_full_Node1 = new node();
			New_full_Node1->data = data;
			New_full_Node1->next = nullptr;
			head = New_full_Node1;
			return;
		}
		node *temp = head;
		while (temp->next != nullptr)
		{
			temp = temp->next;
			// temp->next;// is ki zrorat nhi ha shayad bcz temp man har dafa next node store hojata ha
		}
		temp->data = data;
	}
	void update_at_pos(int val, int pos)
	{
		// Fix: update node at 0-based index pos. Do not replace head when pos==0.
		if (head == nullptr)
		{
			cout << "Linked List is Empty" << endl;
			return;
		}
		if (pos < 0)
		{
			cout << "Invalid position" << endl;
			return;
		}
		node *temp = head;
		int count = 0;
		while (count < pos && temp != nullptr)
		{
			temp = temp->next;
			count++;
		}
		if (temp == nullptr)
		{
			cout << "Position out of range" << endl;
			return;
		}
		temp->data = val;
	}
	void del_at_pos(int pos)
	{
		// Fix: implement deletion at 0-based position pos
		if (head == nullptr)
		{
			cout << "Linked List is Empty" << endl;
			return;
		}
		if (pos < 0)
		{
			cout << "Invalid position" << endl;
			return;
		}
		if (pos == 0)
		{
			node *to_del = head;
			head = head->next;
			delete to_del;
			return;
		}
		node *temp = head;
		int count = 0;
		while (count < pos - 1 && temp != nullptr)
		{
			temp = temp->next;
			count++;
		}
		if (temp == nullptr || temp->next == nullptr)
		{
			cout << "Position out of range" << endl;
			return;
		}
		node *node_to_del = temp->next;
		temp->next = node_to_del->next;
		delete node_to_del;
	}
	void del_first()
	{
		if (head == nullptr)
		{
			cout << "Linked List is Empty" << endl;
			return;
		}
		node *temp = head; // temp man head ko rakha
		head = temp->next; // temp ke agle node ko current head man store kr lia
		delete temp;	   // purane head ko del kr dia
	}
	void del_last()
	{
		if (head == nullptr)
		{
			cout << "Linked List is Empty" << endl;
			return;
		}
		// Fix: handle single-node list separately
		if (head->next == nullptr)
		{
			delete head;
			head = nullptr;
			return;
		}
		node *temp = head;
		node *back = nullptr;
		while (temp->next != nullptr)
		{
			back = temp;
			temp = temp->next;
		}
		back->next = nullptr;
		delete temp; // delete last node
	}
	void del_last_node()
	{
		// Provide a safe alias to del_last(): avoid dereferencing when list size < 2
		del_last();
	}
};

// Display List
// Add node at Start
// Add Node at the End
// Add node at Specific Position
// 5. Update last node
// 5. Update first node
// 6. Update node at specific position
//  7. Delete first node
//  8. Delete last node
//  8. Delete at  position

main()
{
	Linked_list l1;
	l1.add_node_atEnd(5);
	l1.add_node_atEnd(10);
	l1.add_node_atEnd(20);
	l1.add_node_atEnd(30);

	l1.display();
	l1.add_at_start(3);
	l1.add_at_start(2);
	l1.add_at_position(7,10);
	l1.display();
l1.update_at_start(1);
l1.update_at_end(25);
l1.update_at_pos(15,10);
l1.display();

}