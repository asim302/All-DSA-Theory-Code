#include <iostream>
#include <stack>
using namespace std;
// Task 5: Implement Queue using Two Stacks
class Queue_by_stacks
{
public:
	stack<int> st1;
	stack<int> st2;
	void enqueue(int x)
	{
		st1.push(x);
	}
	int dequeue()
	{
		if (st2.empty())
		{
			while (st1.empty())
			{
				st2.push(st1.top());
				st1.pop();
			}
		}
	else if (st2.empty())
		{
			cout << "Queue is empty!" << endl;
			return -1;
		}

		int front = st2.top();
		st2.pop();
		return front;
	}
	/*
	Bas ek golden rule yaad rakho:
	Transfer (s1→s2) sirf ek hi condition mein hota hai: jab dequeue call ho AUR s2 khali ho. Baaki har situation mein — chahe enqueue ho ya s2-non-empty dequeue ho — bina kisi transfer ke kaam chal jaata hai.
	*/
};
main()
{
	    Queue_by_stacks q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    cout << q.dequeue() << " ";  // 1
    cout << q.dequeue() << " ";  // 2

    q.enqueue(4);

    cout << q.dequeue() << " ";  // 3
    cout << q.dequeue() << " ";  // 4
}