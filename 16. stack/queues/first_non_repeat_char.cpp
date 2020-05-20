#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

int main(){
    char ch;
    queue <char> qu;
    unordered_map<char, int> mp;
    cin >> ch;
    while (ch != '.'){
        qu.push(ch);
        mp[ch]++;
        while (!qu.empty()){
            if (mp[qu.front()] > 1){
                qu.pop();
            }
            else{
                cout << qu.front() << "\n";
                break;
            }
        }
        if (qu.empty()){
            cout << "-1" << "\n";
            cin >> ch;
        }
    }
    return 0;
}