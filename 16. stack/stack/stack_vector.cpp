#include <iostream>
#include <vector>

using namespace std;

class Stack{
private:
    vector <int> p;
public:
    void push(int data){
        p.push_back(data);
    }  

    bool empty(){
        return p.size() == 0;
    }      

    void pop(){
        if (!empty()){
            p.pop_back();
        }
    }

    int top(){
        return p[p.size()-1];
    }
};

int main(){
    Stack s; //s is object for Stack class

    for (int i=1; i<=5; i++){
        s.push(i*i);
    }

    while (!s.empty()){
        cout << s.top() << "\n";
        s.pop();
    }
    
    return 0;
}
