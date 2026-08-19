#include <iostream>
#include <stack>
using namespace std;

int precedence(char op) {
	if (op == '*' || op == '/') return 2;
	if (op == '+' || op == '-') return 1;
	return 0;
}

string infixToPostfix(string infix) {
	stack<char> s;
	string postfix = "";

	for (char c : infix) {
		// Operand → output mein daalo
		if (isalnum(c)) {
			postfix += c;
		}
		// '(' → push
		else if (c == '(') //agr starting  '(' mile to use bi push krdi 
		{
			s.push(c);
		}
		// ')' → '(' tak pop karo
		else if (c == ')') //jb closing bracket (')') mile to tab tk pop kro jb tk '(' na mil jaye 
		{
			while (!s.empty() && s.top() != '(') 
			{
				postfix += s.top();
				s.pop();
			}
			s.pop();  // '(' ko bhi pop karo
		}
		// Operator
		else {
			while (!s.empty() && precedence(s.top()) >= precedence(c))
			 {
				postfix += s.top();
				s.pop();
			}
			s.push(c);
		}
	}

	// Baaki operators pop karo
	//end pe sb reaming items pop kro stack se
	while (!s.empty()) 
	{
		postfix += s.top();
		s.pop();
	}
	return postfix;
}

int main() {
	string infix;
	cout << "Enter infix expression: ";
	cin >> infix;
	cout << "Postfix: " << infixToPostfix(infix) << endl;
	return 0;
}
