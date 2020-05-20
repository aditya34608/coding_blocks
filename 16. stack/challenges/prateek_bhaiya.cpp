#include <iostream>
#include <stack>

using namespace std;

int main(){
    int q, num, num1;
    stack <int> s;
    cin >> q;
    while(q){
        cin >> num;
        if (num == 1){
            if (s.empty()){
                cout << "No Code" << "\n";
            }
            else{
                cout << s.top() << "\n";
                s.pop();
            }
        }
        if (num == 2){
            cin >> num1;
            s.push(num1);
        }
        q--;
    }
    return 0;
}