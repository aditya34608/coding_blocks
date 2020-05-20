#include <iostream>
#include <stack>

using namespace std;

bool check_xpr(string str){
    stack <char> s;
    for (int i=0; i < str.size(); ++i){
        char cur_char = str[i];
        if (cur_char == '('){
            s.push(cur_char);
        }
        else if (cur_char == ')'){
            if (s.empty() || s.top() != '('){
                return false;
            }
            s.pop();
        }
    }
    return s.empty();
}

int main(){
    string expr;
    cin >> expr;
    
    bool isvalid = check_xpr(expr);
    cout << isvalid;
    return 0;
}