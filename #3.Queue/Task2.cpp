#include <iostream>
#include <queue>
using namespace std;
/*
Task 2: Generate Binary Numbers 
Input: n = 5 
Output: 1, 10, 11, 100, 101 
//Mtlb 1 se n nmbr tk sare binary numbers ko print kro
*/
void generate_binary_number(int n){
queue<string> q;
// Steps
q.push("1"); //1.Sab se pehle 1 push kro q mans
int count = 0;
while(count < n)
{
//q ke front ko print kra ke use nikal do (POP krdo) aur phir us ke sath 0 aur 1 lgake use q man push krna ha
	cout << q.front() << " ";
	count++; //count+ 1 kro (bcz n no. steps tk loop chlana ha)
 // Step 5: front ke 2 "children" bana ke queue mein daalo	
q.push(q.front() +"0");	 
q.push(q.front() +"1");	 
q.pop(); //pop krna zrori ha bcz is se q ka agla element print hoga
//pop end pe krna ha 
//agr upar kren ge to line 20 aur 21 man q.front() ki value ni hogi jo error de gi 

}
}
 main() {
queue<string> q;
cout << "Enter a Number:" << endl;	
int a ;
cin>>a;
generate_binary_number(a);	

/*
Time Complexity 
void func(int n) {
	if(n <= 1) return;
	cout << n;        // yeh sirf O(1) kaam hai, loop nahi
	func(n / 2);       // seedha aage call, koi n baar chalne wala loop nahi
}
Time Complexity : O(logn)
*/
}
/*
//Dry Run
Trace Table (n = 5)
Step	Dequeue(print)	Queue after push (front+0, front+1)
Start	   —	                 ["1"]
1	       1	              ["10", "11"]
2	      10	            ["11", "100", "101"]
3	      11	       ["100", "101", "110", "111"]
4	      100	      ["101", "110", "111", "1000", "1001"]
5	      101	           (loop rukega, count=5=n)
---------------
Output: 1, 10, 11, 100, 101 ✅ — bilkul match kar raha hai.
*/
/*
Time Complexity 
void func(int n) {
	if(n <= 1) return;
	cout << n;        // yeh sirf O(1) kaam hai, loop nahi
	func(n / 2);       // seedha aage call, koi n baar chalne wala loop nahi
}
Time Complexity : O(logn)
*/