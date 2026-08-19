#include <iostream>
#include <stack>
using namespace std;
#define max 11
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
			cout << queue[back] << " is Popped from Queue" << endl;
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
	cout << get_front() << " ";
	pop();
}	
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
	q.display();
	q.current_size();
	cout << "Queue:" << endl;
	q.push(5);
	q.push(7);
	q.push(9);
	q.push(12);
q.display();
q.current_size();

	
}