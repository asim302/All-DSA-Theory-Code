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
			New_full_Node2 = new_full_node(data); // ek pora node bn gya
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
		//temp man loop ke end par last wala node ajaye ga
		node *end_node = new node();
		end_node->data = data;
		end_node->next = nullptr;
		temp->next = end_node;
	}

	void add_at_position(int val, int pos)
	{
		// Fix: treat pos as 0-based index. If pos==0 insert at start without losing list.
		if (pos <= 0 || head == nullptr) // agr pos <0 ha ya head nulL HA TO start pe add kr do 
		{
			node *node1 = new_full_node(val);
			node1->next = head; // connect to existing list (may be nullptr)
			head = node1;
			return;
		}
		node *temp = head;
		int count = 0; 
		// Move temp to the node at index pos-1 (or last node if pos is beyond length)
		while (count < pos - 1 && temp->next != nullptr) //pos - 1 se bi temp man pos wala node store hojaye ga
		{
			temp = temp->next;
			count++;
		}
		node *node2 = new_full_node(val); // isi line se ek complete node bn jaye ga
		node2->next = temp->next; //1.node2 ko temp->next(agle node) se jor diya
		//1) node2 man temp se agla rakh dia 
		// insert after temp
		temp->next = node2;//2.pichle node ko bi node2 se jor diya
		//2) temp ka next mn node 2 rakh dia bcz uska next ab update hogya hac
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
			// temp->next; // is ki zrorat nhi ha bcz temp man har dafa next node store nhi hota
		}
		temp->data = data;
	}
	void update_at_pos(int val, int pos)//is se node se agla node update hoga
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
		if (temp == nullptr)// agr pos end se age ha to
		{
			cout << "Position out of range" << endl;
			return;
		}
		temp->data = val;
	}
	void del_at_pos(int pos)
	{
		// Fix: implement deletion at 0-based position pos
		//Position ke 2 Cases hoskte han 
		//1.pos <0 hoskti ha 
		//2.pos 0 hoskti ha       3.head null bi hoskta ha
		//Is 3 cases ko sepeately coover krna ha 
		if (head == nullptr) //3.
		{
			cout << "Linked List is Empty" << endl;
			return;
		}
		if (pos < 0) //1.
		{
			cout << "Invalid position" << endl;
			return;
		}
		if (pos == 0) //2.
		{
			node *to_del = head;
			head = head->next; // head mn head ka next rakh dia 
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
		//Position wale operation out of range zror dalna ha bcz position to end se age hoskti ha
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
		//Possible Cases
//1. head null ha 2.sirf ek node ha 3.more than one nodes han		
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
		/*
		last del krne ke liye last se pichle node ki postion ko bi track kiya 
		*/
		node *temp = head;
		node *back = nullptr;
		while (temp->next != nullptr)
		{
			back = temp;//1.back man current temp rakh dia
			temp = temp->next;//2.aur temp man current temp ka next rakh dia
			//is trah temp se pichla node bi track hoga
		}
		back->next = nullptr; //2nd last node ke next man null rakh dia
		delete temp; // delete last node
	}
	void del_last_node()
	{
		// Provide a safe alias to del_last(): avoid dereferencing when list size < 2
		del_last();
	}
	void count_nodes(){
		node* temp = head;
		int count = 0;
		while (temp!= nullptr)
		{
			count++;
			temp = temp->next;
		}
	cout << "Total No. of Nodes: "<< count<< endl;	
	}	
	void find_middle(){
		node* temp = head;
		int count = 0;
		while (temp!= nullptr)
		{
			count++;
			temp = temp->next;
		}
		int mid = count/2;
		cout << "The middle of Linked List is node no. "<< mid<< endl;
/*Q12. Find the Middle Node of a Linked List 
Write two approaches to find the middle node: 
1. By counting total nodes 
2. By slow and fast pointer technique 
Explain: 
• how slow and fast pointers work 
• why they meet if a cycle exists 
• time and space complexity
*/ 
		
		
	}
	void find_key(int key)
	{
		int comparisons = 1;
		// int pos =1;
		bool found = false;
		node* temp = head;
		while (temp != nullptr)
		{
			if(temp->data == key)
			{
				cout << "Key found at node position "<< comparisons<<" with "<< comparisons<<" comparisons"<< endl;
				found = true;
				return ;
			}
			temp = temp->next;
			comparisons++;
		}
		if(found == false)
		{
					cout << "Key Not found" << endl;
		}
		
	}
	// Q9. Search in Singly Linked List return node position,no of comparisons,found or not 
/*
Q15. Merge Two Sorted Linked Lists 
Given two sorted singly linked lists, merge them into a single sorted linked list. 
*/
void merge_two_lists(Linked_list l1,Linked_list l2)
{
	node* head1= l1.head;
	node* head2= l2.head;
	node *temp = head1;
		while (temp->next != nullptr)
		{
			temp = temp->next;
			// temp->next;
		}
		//temp man loop ke end par last wala node ajaye ga
		node* l1_last_node=temp;
		l1_last_node->next = head2; //2 lists ko link kr dia
	cout << "Merged List" << endl;	
	node* temp2  = head1;
	while(temp2!= nullptr)
	{
		cout <<temp2->data<< " ";
		temp2 = temp2->next;
		
	}	
	return;
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
		l1.display();
	l1.add_at_position(7,3); // pos 3 ke next man new node add hoga
	l1.display();
	cout << "______________" << endl;
l1.update_at_start(1);
l1.update_at_end(25);
	l1.display();
l1.update_at_pos(9,4);
	l1.display();
	cout << "______________" << endl;
		l1.add_at_position(10,5);
		l1.add_node_atEnd(30);
		l1.display();
	l1.del_first();
	l1.del_last();
			l1.display();
	l1.del_at_pos(6); //del_at_pos mn hamesha position wale node se agla node delete hoga
				l1.display();
l1.count_nodes();
	cout << "______________" << endl;
l1.find_key(20);
l1.find_key(7);
	cout << "______________" << endl;
Linked_list l2;
l2.add_node_atEnd(25);
l2.add_node_atEnd(30);
l2.add_node_atEnd(35);
l2.add_node_atEnd(40);
	cout << "______________" << endl;

l1.merge_two_lists(l1,l2);

}