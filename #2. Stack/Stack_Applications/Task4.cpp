#include <iostream>
#include <cctype> 
#include <stack> 
using namespace std;

/*
 Task 4: Postfix Expression Evaluation 
Example: 
Postfix: 23*54*+9- 
Result: 
17 
Students must evaluate postfix expressions using stack. 
*/
int evaluate_postfix(string str)
{
	stack<char> st1;
	int result;
	for(char ch : str)
	{
		if(ch>= '0' && ch <= '9') //CHECK KRO ch 0 aur 9 ke b/t ha
		{
st1.push(ch);
		}
		// else if(ch != '+' && ch != '-' && ch != '*' && ch != '/')
		// {
		// 	cout << "Wrong Expression" << endl;
		// }
		else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') 
		{
			int val1 = st1.top();
			st1.pop();
			int val2 = st1.top();
			st1.pop();
			char op1 = ch;
			// int ans = val1 (op1) val2; 
			
			// st1.push(ans);
		}
		// else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') 
		// {
		// 	int val1 = st1.top();
		// 	st1.pop();
		// 	int val2 = st1.top();
		// 	st1.pop();
		// 	char op1 = ch;
		// 	int ans = val1 (op1) val2; 
		// }
	}
}
 main() {
   	string str1;
	cout << "Enter Your Postfix Expression:" << endl;
	cin >> str1;
	
	
}
