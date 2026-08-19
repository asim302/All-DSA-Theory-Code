
#include <iostream>
#include <stack>
using namespace std;
/*
Task 3: Infix to Postfix Conversion 
Example 
Infix expression: 
A + B * C 
Postfix expression: 
ABC*+ 
Students must implement the algorithm using stack. 
"2 3 4 * +"     → 14
"5 1 2 + 4 * +" → 17
"6 2 /"         → 3
"4 5 1 2 + * -" → -11
*/
int precedence (char op)
{
	if(op =='+' || op =='-' )
	{
		return 1;
	}
	else if(op =='*' || op =='/' )
	{
		return 2;
	}
}
string infix_to_postfix(string str)
{
    string postfix = "";
    stack<char> st1;
    
    for(char c : str)
    {
        // Rule 1: operand hai to seedha postfix mein daal do
        if(isalnum(c))
        {
            postfix += c;
        }
        // Rule 2: operator hai
        else
        {
            while(!st1.empty() && precedence(st1.top()) >= precedence(c))
            {
                postfix += st1.top();
                st1.pop();
            }
            st1.push(c);
        }
    }
    
    // Rule 3: jo bhi bacha hai stack mein, nikal do
    while(!st1.empty())
    {
        postfix += st1.top();
        st1.pop();
    }
    
    return postfix;
}
//With Brackets
string infix_to_postfix2(string str)
{
    string postfix;
    stack<char> st1;
    
    for(char c : str)
    {
        // Rule 1: operand
        if(isalnum(c))
        {
            postfix += c;
        }
        // Rule 2: opening bracket → seedha push
        else if(c == '(')
        {
            st1.push(c);
        }
        // Rule 3: closing bracket → jab tak '(' na mile, pop karte raho
        else if(c == ')')
        {
            while(!st1.empty() && st1.top() != '(')
            {
                postfix += st1.top();
                st1.pop();
            }
            st1.pop();   // ye '(' ko nikaal deta hai, postfix mein nahi jata
        }
        // Rule 4: normal operator
        else
        {
            while(!st1.empty() && st1.top() != '(' && precedence(st1.top()) >= precedence(c))
            {
                postfix += st1.top();
                st1.pop();
            }
            st1.push(c);
        }
    }
    
    while(!st1.empty())
    {
        postfix += st1.top();
        st1.pop();
    }
    
    return postfix;
}
 main() {
	string str1;
    cout << "Enter Your Infix Expression:" << endl;
    cin >> str1;
    
    cout << "Postfix Expression: " << infix_to_postfix(str1) << endl;
    
	
}