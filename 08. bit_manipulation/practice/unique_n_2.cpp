//Find unique numbers given in an array

#include <bits/stdc++.h>

using namespace std;

int main(){
    int tmep, pos = 0, i, a[i], n, no, res = 0;
    cin >> n;
    for (i=0; i < n; i++){
        cin >> no;
        a[i] = no;
        res = res ^ no;
    }  
    int temp = res;
    while ((temp + 1) == 1){
        pos++;
        temp = temp >> 1;
    }
    int mask = (1 << pos);
    int x = 0, y = 0;
    for (i=0; i < n; i++){
        if ((a[i] & mask) > 0){
            x = x ^ a[i];
        }
    }
    y = res ^ x;
    cout << min(x, y) << " " << max(x, y) << "\n";
    return 0;
}
