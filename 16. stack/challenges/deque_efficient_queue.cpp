/*

Implement a Queue using two stacks Make it Dequeue efficient.
Input Format

Enter the size of the queue N add 0 - N-1 numbers in the queue
Constraints

Output Format

Display the numbers in the order they are dequeued and in a space separated manner
Sample Input

5

Sample Output

0 1 2 3 4

*/
#include <bits/stdc++.h> 
using namespace std; 
  
class Queue { 
private:
    stack<int> s1, s2;
  
public:
 
    void enQueue(int x) 
    {
        while (!s1.empty()) { 
            s2.push(s1.top()); 
            s1.pop(); 
        } 
        s1.push(x); 
  
        while (!s2.empty()) { 
            s1.push(s2.top()); 
            s2.pop(); 
        } 
    }
  
    int deQueue() 
    { 
        if (s1.empty()) { 
            exit(0);   
        } 
  
        int x = s1.top(); 
        s1.pop(); 
        return x;  
    } 
};

int main() 
{ 
    Queue q; 
    int n;
    cin >> n;
    int m = n;
    for(int i = 0; i < n; i++){
        q.enQueue(i); 
    }

    for(int i=0;i<m;i++)
    {
         cout<<q.deQueue()<<" "; 
    }
  
    cout<< "\n";
  
    return 0; 
}