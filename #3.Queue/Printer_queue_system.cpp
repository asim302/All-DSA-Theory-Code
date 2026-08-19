#include <iostream>
#include <queue>
using namespace std;
class Printer_system
{
public:
	queue<string> q1;
	
	void add_task()
	{

		cout << "Enter File name to be Printed" << endl;
		string b;
		cin >> b;
		q1.push(b);
	}
	void check_first()
	{
		if (q1.empty())
		{
			cout << "No tasks to Check!" << endl;
			return;
		}
		cout << "Task at Most Priority" << endl;
		cout << q1.front()<< endl;
	}
	void complete_task()
	{
		if (q1.empty())
		{
			cout << "No tasks to complete!" << endl;
			return;
		}
		cout << q1.front() << "  is Printed" << endl;
		q1.pop();
	}
	void display_task()
	{
		if (q1.empty())
		{
			cout << "No tasks to Display!" << endl;
			return;
		}
		queue<string> temp = q1; // copy banake print karo, original safe rahe
		while (!temp.empty())
		{
			cout << temp.front() <<endl;
			temp.pop();
		}
		cout << endl;
	}
	  void addTaskDirect(string name)
	{
		q1.push(name);
	}
};
int main_menue()
{
	cout << "===Printer System by Queue ===" << endl;
	cout << "1.Add Printer Task" << endl;
	cout << "2.Check printer Task to be done Fisrt" << endl;
	cout << "3.Complete a Printer Task (that is on most priority)" << endl;
	cout << "4.Display Tasks" << endl;
	cout << "___________________" << endl;
	cout << "Enter Your Choice" << endl;
	int a;
	cin >> a;
	return a;
}

main()
{
	Printer_system p;
	p.addTaskDirect("Assignment.pdf");
	p.addTaskDirect("Resume.docx");
	p.addTaskDirect("Notes.txt");
	int op = main_menue();
	while (op != 5)
	{
		if (op == 1)
		{
			p.add_task();
		}
		else if (op == 2)
		{
			p.check_first();
		}
		else if (op == 3)
		{
			p.complete_task();
		}
		else if (op == 4)
		{
			cout << "===Printer TASKS in Waiting Queue===" << endl;
			p.display_task();
			int a;
			cin>>a;
			cout << "Press any key" << endl;
		}
		
		else
		{
			cout << "Invalid Choice." << endl;
						cout << "Exiting.." << endl;

		}
					int op = main_menue();

	}
}