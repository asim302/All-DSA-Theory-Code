// 4. Write a program to reverse the elements of an array.
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
    // int *first = array;
    // int *second = (array + num);
    // let array = {1,2,3,4}
     int start = 0;
    int end = (num-1); // let: end = 3
   while(start < end)
   {
 int temp = array[start]; // temp = 1
        array[start] = array[end]; // array[0] = 4
        array[end] = temp; // array[3] = temp ==> 4 = temp
        start++;
        end--;
   }
    
    
    cout << "Reversed Array elements: "<<endl;;
    for (int i = 0; i < num; i++)
    {
       cout<<array[i]<<" ";
    }
    
    
    
}
