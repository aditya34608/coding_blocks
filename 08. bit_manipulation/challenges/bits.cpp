#include <bits/stdc++.h>

using namespace std;

long long playwithbits(long long a){
    int ans = 0;
    for (; a > 0; a = a >> 1){
        ans += a & 1;
    }
    return ans;
}

int main(){
    long long q, a, b, ans;
    cin >> q;
    while (q != 0){
        cin >> a >> b;
        ans = 0;
        for (long long i = a; i <= b; i++){
            ans += playwithbits(i);
        }
        cout << ans << "\n";
        q--;
    }
    return 0;
}
