/*
Write a program to perform the following operations on an array:
*/
#include <iostream>
using namespace std;
const int MAX = 100;
int array[MAX];
int arr_size = 0; // Track current size of array
// • traverse
void traverse()
{
	if (arr_size == 0)
	{
		cout << "Array is Empty..." << endl;
		return;
	}
	for (int i = 0; i < arr_size; i++)
	{
		cout << array[i] << ",";
	}
	cout << endl;
}
// • insert at beginning
void insert_at_start(int val)
{
	if (arr_size >= MAX)
	{
		cout << "Array is Full" << endl;
		return;
	}
	for (int i = arr_size; i >= 0; i--)
	{
		array[i + 1] = array[i];
	}
	array[0] = val;
	arr_size++;
}
// • insert at end
void insert_at_end(int val)
{
	array[arr_size] = val;
	arr_size++;
}
// • insert at any position
void insert_at_position(int pos, int val)
{
	for (int i = arr_size; i >= pos; i--)
	{
		array[i + 1] = array[i];
	}
	array[pos] = val;
	arr_size++;
}
// • delete from beginning
void del_at_start()
{
	for (int i = 0; i < arr_size; i++)
	{
		array[i] = array[i + 1];
	}
	arr_size--;
}
// • delete from end
void del_from_end()
{
	arr_size--;
}
// • delete from any position
void del_from_position(int pos)
{
	for (int i = pos; i < arr_size; i++)
	{
	array[i]=array[i+1];
	}
arr_size--;
}
// • search an element
bool search(int element)
{
	bool found = false;
	int count = 0;
	for (int i = 0; i < arr_size; i++)
	{
		if (array[i] == element)
		{
			found = true;
		}
		count = i;
	}
	if (found)
	{
		cout << "Element Found at Index " << count << endl;
	}
	else
	{
		cout << "Element not Found " << count << endl;
	}
}

// Q4. Find Second Largest and Second Smallest in an Array
// void find_second_largest()
// {
// 	int largest ;
// 	int second_largest = 0;
// 	for (int i = 0; i < arr_size; i++)
// 	{
		
// 	}
// }
// Q5. Reverse an Array In-Place
void reverse_array()
{
	int start = 0;
	int end = arr_size -1;
	while(start < end)
	{
		swap(array[start],array[end]);
		start++;
		end--;
	}
	cout << "Reversed Array" << endl;
	traverse();
}
	//Alternative
void reverse2()
{
	int start = 0;
	int end = arr_size -1;
	 while (start < end)   // jab tak dono mil na jayein
	{
		int temp = array[start];   // pehli value temporary box me rakhi
		array[start] = array[end]; // last value ko first position pe rakh diya
		array[end] = temp;         // temp wali (original first) ko last pe rakh diya

		start++;   // start ko andar move kara
		end--;     // end ko andar move kara
	cout << "Reversed Array" << endl;
	traverse();
	}
	// Q10. Count Even, Odd, Positive, and Negative Nodes and counts of each
}
void merge_two_Arrays(int arr1[],int size1,int arr2[],int size2)
{
	int arr3[100];
	int size = 0;
	for (int i = 0; i < size1; i++)
	{
		 arr3[i] = arr1[i];
		 size++;
	}
	for (int j = 0; j < size2; j++)
	{
		arr3[size] = arr2[j];
		size++;
	}
	cout << "Merged Array" << endl;
	for (int i = 0; i < size; i++)
	{
		cout << arr3[i]<< " ";
	}
	
	// return arr3;
	
	
}

main()
{
	traverse();
	insert_at_end(2);
	insert_at_end(4);
	insert_at_end(6);
	insert_at_end(8);
	insert_at_end(16);
	insert_at_end(32);
	traverse();
	insert_at_start(1);
	insert_at_start(0);
	insert_at_position(3,3);
	traverse();
	insert_at_position(5,5);
	traverse();
	search(16);
	del_at_start();
	traverse();
	// del_at_start(); //ye thek kam ni kr rha
	// 	traverse();
	del_from_end();
		traverse();	
	del_from_end();
		traverse();	
	del_from_position(6);
	traverse();
	del_from_position(0);
	traverse();
cout << "_______________" << endl;
reverse_array();
cout << "_______________" << endl;
int arr3[3]= {1,2,4};
int arr4[3]= {5,8,9};
int size = sizeof(arr3)/4;
cout << "Size of arr3 is " <<size << endl;
	int size1= sizeof(arr3)/4 ;
	int size2= sizeof(arr4)/4 ;
merge_two_Arrays(arr3,size1,arr4,size2);
}

/*
Q5. Reverse an Array In-Place 
Write a function to reverse an array without using extra array space. 
Then answer: 
• What is the time complexity? 
• Why is this called an in-place algorithm? 
• Can this be done recursively?
*/