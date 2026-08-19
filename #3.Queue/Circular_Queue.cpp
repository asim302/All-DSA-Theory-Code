#include <iostream>
using namespace std;
#define size 5 
//# wali line man ; nhi lgate han
 
class Circular_queue { 
    int arr[size]; 
    int front;
    int back;
    int arrsize;  // Current Size
    int capacity;
public:
 Circular_queue(){
// Start man front aur rear ko -1 pe rakh do
front = 0; // ab front ko naya element ana par ek step age kren ge  bas 
back = -1;
arrsize=0;
capacity=size;
 }
bool isEmpty(){
if (arrsize == 0) // agr current_size == 0 (No item in queue) 
{
    return true;
}
else return false;
}
bool isFull()
{
  if (arrsize == capacity) // agr current_size == capacity 
{
    return true;
}
   else
   return  false;
}
void enqueue(int x) // Push
{
if(isFull()){
    cout << "Queue Overflow" << endl;
    return ;
}
back = (back +1) % capacity; //Main Logic: 
arr[back] = x;
arrsize++; // queue ka current_size barha diya bcz ek item add hua
}
void dequeue() // pop()
{
    if(isEmpty()){
    cout << "Queue Underflow" << endl;
    return ;
    }
cout << arr[front] << " is deleted" << endl;
front = (front +1) % capacity;
arrsize--; // current_size kam kr diya bcz  front item delete hogya ha
}
void display()
{
    if(isEmpty())
    {
        cout << "Queue is Empty" << endl;
        return;
    }
    int i = front;
    while (true)
    {
        cout << arr[i] << " ";

        if (i == back)  // Jab i ghom kar wapis back pe ajaye tb break krdo
            break;

        i = (i + 1) % capacity; // circular move
    }

    cout << endl;
}

};

 main() {
  Circular_queue q;

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

    q.display(); 
}