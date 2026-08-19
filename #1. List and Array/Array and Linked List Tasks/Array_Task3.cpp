// 3. Write a program to calculate the sum of all elements of an array.
#include <iostream>
using namespace std;

main()
{
	int num;
	cout << "Enter Number of Elements in array :" << endl;
	cin >> num;
	int array[num];
	int a = 1;

	for (int i = 0; i < num; i++)
	{
		cout << "Enter Element " << i + 1 << ": " << endl;
		cin >> array[i];
		
		
	}

	float sum=0;
 for (int i = 0; i < num; i++)
	{
		sum = sum + array[i];
	}
cout << "Total Sum of the Array Elements is : "<<sum << endl;
}
