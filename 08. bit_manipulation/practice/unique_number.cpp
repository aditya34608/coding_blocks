/* Unique Number 2N + 1
Given a list of numbers where every numbers occurs twice
exxcept one, find the number
*/

#include <bits/stdc++.h>

using namespace std;

int main(){
    int t, ans = 0, num;
    cin >> t;
    for (int i=0; i<t; i++){
        cin >> num;
        ans = ans ^ num;
    }
    cout << ans << "\n";
    return 0;
}