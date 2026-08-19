#include <iostream>
using namespace std;

int main()
{
	int num;
	cout << "Enter Number of Elements in array :" << endl;
	cin >> num;

	int array[num];

	// Taking Input in Array
	for (int i = 0; i < num; i++)
	{
		cout << "Enter Element " << i + 1 << ": " << endl;
		cin >> array[i];
	}

	// Reverse Logic Start

	int start = 0;        // first index
	int end = num - 1;    // last index

	while (start < end)   // jab tak dono mil na jayein
	{
		int temp = array[start];   // pehli value temporary box me rakhi
	//1.temp man start wali value save krli
		array[start] = array[end]; // last value ko first position pe rakh diya
	//2.start index pe last wali value rakh di	
		array[end] = temp;         // temp wali (original first) ko last pe rakh diya
	//3. end pe last index pe temp(start wali value) ko rakh dia	

		start++;   // start ko andar move kara
		end--;     // end ko andar move kara
	}

	// Printing Reversed Array
	cout << "Reversed Array Elements are: " << endl;
	for (int i = 0; i < num; i++)
	{
		cout << array[i] << " ";
	}
}