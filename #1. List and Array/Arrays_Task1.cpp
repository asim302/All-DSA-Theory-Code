// Arrays :
// 1. Write a program to find the maximum element in a given array.
#include <iostream>
using namespace std;

 main() 
{
	int num = 5;

/*	
cout<<"Enter Number of Elements in array :"<<endl;
cin>>num;
int array[num];

 for (int i = 0; i < num; i++) {
				cout<<"Enter Element "<<i+1<<": "<<endl;
				cin>>array[i];
		}
	*/	

int array[num] = {1,12,4,5,2};

		int largest = array[0];
		int second_largest = array[0];
 for (int i = 0; i < num; i++) 
 {
	 if (array[i]>=largest)
	 {
			 largest = array[i];
	 }
 }
for (int i = 0; i < num; i++) 
 {
	 if (array[i]<(largest-1))
	 {
			 second_largest = array[i];
	 }
 }
 cout << "Largest Number of the Array is : " << largest<< endl;
 cout << "And Second Largest Number of the Array is : " << second_largest<< endl; //Failed 
 //Bad mn kren ge

		
}