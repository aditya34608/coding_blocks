#include <iostream>
#include <vector>

using namespace std;

//we can have multiple datatypes
template <typename t>
class Stack{
private:
    vector <t> p;
public:
    void push(t data){
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

    t top(){
        return p[p.size()-1];
    }
};

int main(){
    /*
    Stack <int> s; //s is object for Stack class

    for (int i=1; i<=5; i++){
        s.push(i*i);
    }

    while (!s.empty()){
        cout << s.top() << "\n";
        s.pop();
    }
    */

    Stack <char> s;

    for (int i=65; i <= 70; i++){
        s.push(i);
    }

    while (!s.empty()){
        cout << s.top() << "\n";
        s.pop();
    }    
    return 0;
}
