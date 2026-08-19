#include <iostream>
using namespace std;
#define max 50
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
	cout << val<< " pushed into Stack" << endl;
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

void display(){

//Note: display man FIFO Principal Use krna ha
for (int i = top; i >= 0; i--)
{
	cout << arr[i] <<" ";
}
//NOTE: EK line man display krne ka bad endl zror lgayeb
	cout<< endl;

}
};
 main() {
	
	Stack s1;
		cout << "Stack s1" << endl;
	s1.push(5);
	s1.push(10);
	s1.push(15);
	s1.push(20);
	s1.display();
	// s1.is_Empty();
	s1.pop();
	s1.peek();
	Stack s2;
	cout << "Stack s2" << endl;
	s2.push(1);
	s2.push(3);
	s2.push(5);
	s2.push(7);
	s2.push(9);
	s1.display();
	s2.peek();
	s2.pop();
	s2.pop();

}