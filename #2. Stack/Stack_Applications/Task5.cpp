#include <iostream>
#include <stack>
using namespace std;
/*
Task 5: Decimal to Binary using Stack 
Convert a decimal number to binary representation using stack. 
*/
void decimal_to_binary(int num)
{
	stack<int> st1;	
	int res;
	while(num>0)
	{
		int remainder = (num%2);
		st1.push(remainder);	
		num= num/2;
	}
	
//Loop ke end pe stack man full binary digit ajaye ga	
cout << "Binary Number: " << endl;
while (!st1.empty())
{
	int a = st1.top();
	st1.pop();
	cout << a << " ";
}

}
 main() 
{ 
	int num;
	cout << "Enter a Decimal to Convert into Binary" << endl;
	cin>>num;
	decimal_to_binary(num);
}
