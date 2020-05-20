#include <bits/stdc++.h>

using namespace std;

int main(){
    int cnt[64] = {0}, n, no;
    cin >> n;

    for (int i=0; i < n; n++){
        cin >> no;
        //update count array by extracting bit
        int j =0;
        while ( no > 0){
            int last_bit = (no & 1);
            cnt[j] += last_bit;
            j++;
            no = no >> 1;
        }
    } 
    //iterate over the array
    int p = 1;
    int ans = 0;
    for (int i=0; i < 64; i++){
        cnt[i] %= 3;
        ans += (cnt[i] *p);
        p = p << 1;
    }

    cout << ans << "\n";

    return 0;
}
