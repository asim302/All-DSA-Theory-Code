#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int n = 5;   // kitne binary numbers chahiye

    queue<string> q;   // STL queue jo strings store karegi

    // Step 1: Queue mein starting point daal do -> "1"
    // Kyunki koi bhi binary number "0" se start nahi hota (leading zero allowed nahi)
    q.push("1");

    int count = 0;   // kitne numbers ab tak print ho chuke hain, uska counter

    // Step 2: Loop tab tak chalao jab tak n numbers print na ho jayein
    while (count < n)
    {
        // Step 3: Queue ke front wala element nikaalo (ye hamara "current" number hai)
        string front = q.front();
        q.pop();   // usko queue se remove kar do (FIFO principle)

        // Step 4: Isko print karo -> ye humara result hai
        cout << front << " ";
        count++;   // ek number print ho gaya, counter badhao

        // Step 5: Is number ke 2 "children" bana ke queue mein daalo
        // child 1: front + "0"  (jaise "1" -> "10")
        // child 2: front + "1"  (jaise "1" -> "11")
        // Ye is liye kyunki agla number ya to isi ke end mein 0 laga ke banega
        // ya 1 laga ke -> BFS tree jaisa structure
        q.push(front + "0");
        q.push(front + "1");
    }

    cout << endl;
    return 0;
}