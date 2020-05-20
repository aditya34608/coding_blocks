// Power using Bitmasking

#include <bits/stdc++.h>

using namespace std;

int power(int a, int n){
    int ans = 1;
    while (n > 0){
        int last_digit = (n & 1);
        if (last_digit){
            ans = ans * a;
        }
        a = a * a;
        n = n >> 1;
    }
    return ans;
}

int main(){
    int a, n;
    cin >> a >> n;

    cout << power (a, n) << "\n";
    return 0;
}
