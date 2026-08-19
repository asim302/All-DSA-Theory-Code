#include <iostream>
#include <string>
#include <stack>
#define max 50
using namespace std;
/*
Task 1: Reverse a String using Stack
Objective
Use stack to reverse a string.
Algorithm
1. Read a string
2. Push all characters into stack
3. Pop characters one by one
4. Construct reversed string
*/

class Stack
{
	int arr[max];
	int top;

public:
	Stack()
	{
		top = -1;
	}
	// void is_Empty()
	// {
	// 	if(top<0)
	// 	{
	// 		cout << "Stack Underflow" << endl;
	// 	}
	// 	return;
	// }
	void push(int val)
	{

		top++;
		arr[top] = val;
		cout << val << " pushed into Stack" << endl;
	}
	void pop()
	{
		cout << arr[top] << endl;
		cout << "Top Element is Popped" << endl;
		top--;
	}
	void peek()
	{

		cout << "Top Element" << endl;
		cout << arr[top] << endl;
	}

	void display()
	{

		// Note: display man FIFO Principal Use krna ha
		for (int i = top; i >= 0; i--)
		{
			cout << arr[i] << " ";
		}
		// NOTE: EK line man display krne ka bad endl zror lgayeb
		cout << endl;
	}
};

main()
{
	// Stack s2;
	cout << "Enter a String:" << endl;
	string string1;
	cin >> string1;
	// Every string is an array
	//  int l1 = s1.capacity();
	//  cout << "Length of String"<< l1 << endl;

	stack<char> s;
	for (char c : string1)
	{
		s.push(c);
	}

	while (!s.empty())
	{
		cout << s.top() << endl;
		s.pop();
	}
	
}