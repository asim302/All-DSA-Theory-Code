#include <iostream>
#include <stack>
using namespace std;
#define max 11
// Task 1: Reverse Queue 
// Use stack to reverse queue. 
class Queue
{
public:
	int queue[max];
	int front;
	int back;
	bool is_empty()
	{
		if (front == -1 && back == -1)
		{
			return true;
		}
		return  false;
		
	}
	bool isFull()
	{
		if (back == (max - 1)) // Agr tail ka item index ke end pe pra ha to index full ha
		{
			return true;
		}
		else
			return false;
	}
	Queue()
	{
		front = -1;
		back = -1;
	}
	void push(int val)
	{
		if (isFull())
		{
			cout << "Queue is Full (Queue Overflow)" << endl;
		}
		else if (front == -1)
		{
			front = back = 0;
			queue[back] = val;
		}
		else
		{
			back++;
			queue[back] = val;
		}
	}
	void pop()
	{
		if (is_empty())
		{
			cout << "Queue is empty" << endl;
		}
		else if (front == back)
		{
			front = back = -1;
		}
		else
		{
			front = front + 1;  
		}
	}
	int get_front()
	{
		if (is_empty())
		{
			cout << "Queue is empty" << endl;
			return -1;
		}
		return queue[front];
	}
void get_front2()
{
	cout << "Front Element:" << endl;
	cout << queue[front] << endl;
}
void display()
{
for (int i = front; i <= back; i++)
{
	// int a = get_front()
	cout << queue[i] << " ";
	
}
cout<< endl;
}	
int back_val()   // STL jaisa naam "back" member variable se clash karega, isliye alag naam
{
	if (is_empty())
	{
		cout << "Queue is empty" << endl;
		return -1;
	}
	return queue[back];
}
int current_size()
{
	if (is_empty())
	{
		return 0;
	}
	return (back - front + 1);
}
};

main()
{
	Queue q;
	q.pop();
	// q.current_size();
	cout << "Size: " << q.current_size() << endl;
	cout << "Queue:" << endl;
	q.push(5);
	q.push(7);
	q.push(9);
	q.push(12);
   q.display();
//    q.current_size();
cout << "Size: " << q.current_size() << endl; //Note :size print bi krna tha

stack<int> st;
while(q.current_size() != 0)
{
	int a = q.get_front();
	st.push(a);
	q.pop();
}
cout << "Reversed Queue By Stack " << endl;
	int a = st.top();
while(st.size() != 0)
{
	int a = st.top();
	cout << a << " ";
	st.pop();
}

	
};