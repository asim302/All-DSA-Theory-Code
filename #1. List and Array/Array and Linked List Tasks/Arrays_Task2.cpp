// 2. Write a program to find the minimum element in a given array.
#include <iostream>
using namespace std;

main() 
{
int num;
cout<<"Enter Number of Elements in array :"<<endl;
cin>>num;
int array[num];

 for (int i = 0; i < num; i++) {
        cout<<"Enter Element "<<i+1<<": "<<endl;
        cin>>array[i];
    }
    int smallest = array[0];
 for (int i = 0; i < num; i++) 
 {
   if (array[i]<=smallest)
   {
       smallest = array[i];
   }
   
 }

 cout << "Smallest Number of the Array is : " << smallest<< endl;

    
}
