#include <iostream>
#include <stack>
using namespace std;
/*
Task 2: Check Balanced Parentheses
Example:
Input: {(a+b)*(c+d)}
Output: Balanced
Students must implement a program that checks whether parentheses are balanced.
*/
string check_Balanced_expression(string str1)
{
	stack<char> s1;
	for (char c : str1)
	{
		if (c == '{' || c == '(' || c == '[')
		{
			s1.push(c);
		}
		else if (c == '}' || c == ')' || c == ']')
		{
			if (s1.empty())
			{
				return "Unbalanced Expression";
			}
			else
			{
				s1.pop();
			}
		}
	}
	if (s1.empty())
	{
		return "Balanced Expression";
	}
	else
	{
		return "Unbalanced Expression";
	}
}
string check_Balanced_expression(string str1)
{
	stack<char> s1;
	for (char c : str1)
	{
		if (c == '{' || c == '(' || c == '[')
		{
			s1.push(c);
		}
		else if (c == '}' || c == ')' || c == ']')
		{
			if (s1.empty())
			{
				return "Unbalanced Expression";
			}
			else
			{
				s1.pop();
			}
		}
	}
	if (s1.empty())
	{
		return "Balanced Expression";
	}
	else
	{
		return "Unbalanced Expression";
	}
}
//2nd Version
string check_Balanced_expression2(string str1)
{
	stack<char> s1;
for(char c : str1)
{
if( c== '{' || c== '(' || c == '['){
	s1.push(c);
}
else if( c== '}' || c== ')' || c == ']')
{
	if(s1.empty())
	{
	  return "Unbalanced Expression";
	}
	else{
		char top = s1.top();
		s1.pop();
		if(c== '}' && top!= '{' || c== ')' && top!= '(' || c== ']' && top!= '[')
		{
		  return "Invalid Expression";
		
		}
	}
}
}	
if(s1.empty())
{
	return "Balanced Expression";
}
else
{
		  return "Unbalanced Expression";
}
}

main()
{
	string str1;
	cout << "Enter Your Expression:" << endl;
	cin >> str1;
	string str2 = check_Balanced_expression(str1);
	cout << str2 << endl;
	// string str2 = check_Balanced_expression2(str1);
	// cout << str2 << endl;
}
