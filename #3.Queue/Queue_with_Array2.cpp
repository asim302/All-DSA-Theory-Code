#include <iostream>
using namespace std;
#define size 5 
//# wali line man ; nhi lgate han
 
class Queue { 
	int arr[size]; 
	int front;
	int back;
public:
 Queue(){
// Start man front aur rear ko -1 pe rakh do
front = -1;
back = -1;

 }
bool isEmpty(){
if (front == -1 && back == -1){
	return true;
}
else return false;
}
bool isFull()
{
   if (back == (size - 1) ) // Agr tail ka item index ke end pe pra ha to index full ha 
   {
return true;
   } 
   else
   return  false;
}
void enqueue(int x) // Push
{
bool a = isFull();
if (a == true)
{
cout << "Queue is Full (Queue Overflow) " << endl;
return ;
}
else if(isEmpty()) // Pehli Dafa front ko 0 index pe kr do (Agr Queue empty ha to queue)
{
	front = 0;
	back = 0;
}
else
{
back = back +1; // Har dafa back ko ek index peche kr do
}
arr[back] = x; // aur ab back ko bi ek index age krke  whan x rakh do

}
void dequeue() // pop()
{
bool a = isEmpty();
if(a == true)
{
cout << "Queue Underflow" << endl;
	cout << "Element cannot be extracted because queue is empty " << endl;
	return ;
}
else if (front == back) // Agr sirf ek hi element h queue man
{
front = -1;
back = -1;
}
else
{
// Har dafa front ko ek index age move kro bcz is ke pichla element delete hogya ha
cout <<arr[front] << " (Front Element) is Deleted" << endl;
front = front + 1;  
}
// cout << arr[front] << endl;
}
void display()
{
if(isEmpty())
{
	cout << "Queue is Empty" << endl;
	return;
}

for (int i =front; i <= back;i++)
{
cout << arr[i]<<" ";
}
cout<< endl;
}

};

 main() {
	Queue q; 
 cout << "=== Enqueue 5 elements ===" << endl;
	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);
	q.enqueue(4);
	q.enqueue(5);

	q.display();

	cout << "\n=== Try Overflow ===" << endl;
	q.enqueue(6);  // should show overflow

	cout << "\n=== Dequeue 2 elements ===" << endl;
	q.dequeue();
	q.dequeue();

	q.display();

	cout << "\n=== Add more elements (circular test) ===" << endl;
	q.enqueue(6);
	q.enqueue(7);

	q.display();

	cout << "\n=== Dequeue all ===" << endl;
	q.dequeue();
	q.dequeue();
	q.dequeue();
	q.dequeue();
	q.dequeue();

	cout << "\n=== Try Underflow ===" << endl;
	q.dequeue();  // should show underflow

	q.display(); 
 

 }
// Queue
/*
-1 0 1 2 3 4 5    (Index)
  ---------------
   2
  ---------------
  // Ab 0 pe hi front aur back ha 
  enqueue(2)
//----------  
  enqueue(4)
-1 0 1 2 3 4 5    (Index)
  ---------------
   2 4
  ---------------
  // Ab 0 pe front aur back 1 pe ha
	q.enqueue(6);
	q.enqueue(8);   
	q.enqueue(9);   
-1 0 1 2 3 4 5    (Index)
  ---------------
   2 4 6 8 9
  --------------- 
  Back Index: 4
  0:FRONT
//Ab dequeue kren ge
dequeue();  
-1 0 1 2 3 4 5    (Index)
  ---------------
   - 4 6 8 9
  --------------- 
Front: 1
dequeue();  
dequeue(); 
q.enqueue(1);
 
-1 0 1 2 3 4 5    (Index)
  ---------------
   - - - 8 9 1
  --------------- 
Front: 3  , Back : 5  

PROBLEM in Simple Queue :
queue man koi alement ni askta ab bcz back end pe but Queue man space ha abi

*/ 
/*
enqueue(2)
enqueue(5)
  0 1 2 3 4 5    (Index)
  ---------------
  5 2
  ---------------
front = 0
back = 1
*/    
