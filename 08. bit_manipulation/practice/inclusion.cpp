/*
find out the number of numbers between 1 and n which 
are divisible by any of the prime number less than 20.
*/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll t, n, primes[] = {2, 3, 5, 7 ,11, 13, 17, 19};
    cin >> t;    
    while (t--){
        ll ans = 0;
        ll subset = ((1 << 8) - 1);
        for (ll i=0; i <= subset; i++){
            ll denom = 1ll;
            ll setbits = __builtin_popcount(i);
            for (ll j=0; j <= 7; j++){
                if (i & (1 << j)){
                    denom = denom * primes[j];
                }
            }
            if (setbits & 1){
                ans += n / denom;
            }
            else
            {
                ans -= n / denom;
            }
        }
    }
    return 0;
}
