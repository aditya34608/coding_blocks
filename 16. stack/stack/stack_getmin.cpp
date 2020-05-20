// time compelexity : O(1)
// space compelexity : O(1)
#include <iostream>
#include <stack>
using namespace std;

struct Stack{
    stack <int> s;
    int minele;

    //minimum element in stack
    void getmin(){
        if (s.empty()){
            cout << "stack is empty\n";
        }
        else{
            cout << "minimum element in the stack is: " << minele << "\n";
        }
    }

    //print top element of stack
    void peek(){
        if (s.empty()){
            cout << "stack is empty";
            return;
        }

        int t = s.top();

        cout << "top element is: ";
        (t < minele) ? cout << minele : cout << t;
    }

    //remove top of stack
    void pop(){
        if (s.empty()){
            cout << "stack is empty" << "\n";
            return;
        }

        cout << "top most element removed: ";
        int t = s.top();
        s.pop();

        if (t < minele){
            cout << minele << "\n";
            minele = 2 * minele - t;
        }

        else{
            cout << t << "\n";
        }
    }
    
    //remove top element from stack
    void push(int x){
        if (s.empty()){
            minele = x;
            s.push(x);
            cout << "number inserted: " << x << "\n";
            return; 
        }

        if (x < minele){
            s.push(2*x - minele);
            minele = x;
        }
        else{
            s.push(x);
            cout << "number inserted: " << x << "\n";
        }
    }    
};

int main(){
    Stack s;
    s.push(3);
    s.push(5);
    s.getmin();
    s.push(2);
    s.push(1);
    s.getmin();
    s.pop();
    s.getmin();
    s.pop();
    s.peek();
    return 0;
}