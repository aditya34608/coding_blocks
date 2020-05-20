#include <iostream>
#include <stack>
using namespace std;

void printspan(int arr[], int n){
    int ans[100] = {};
    stack <int> s;
    for (int day=0; day < n; ++day){
        int curprice = arr[day];
        while (s.empty() == false && arr[s.top()] < curprice){
            s.pop();
        }
        int betterday = s.empty() ? 0 : s.top();
        int span = day - betterday;
        ans[day] = span;
        s.push(day);
    }
    for (int i=0; i < n; ++i){
        cout << ans[i] << " ";
    }
}

int main(){
    int n =7;
    int arr[100] = {100, 80, 60, 70, 60, 75, 85};
    printspan(arr, n);
    return 0;
}