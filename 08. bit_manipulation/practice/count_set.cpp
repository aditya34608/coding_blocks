/*
Given a number N, find number of set bits in binary rep. it 
N = 13, Binary = 1101, Output = 3
*/

#include <bits/stdc++.h>

using namespace std;

//first method
// time complexity : Log N + 1

int countBits(int n){
    int ans = 0;
    while (n > 0){
        ans += (n & 1);
        n = n >> 1;
    }
    return ans;
}

//second method
// time compleity : Number of Set bits can be Log N in WC

int countbitsfast(int n){
    int ans = 0;
    while (n > 0){
        n = n & (n - 1);
        ans++;
    }
    return ans;
}

int main(){
    int n;
    cin >> n;
    cout << countBits(n) << "\n";
    cout << countbitsfast(n) << "\n";
    //third method
    cout << __builtin_popcount(n) << "\n";
    return 0;
}
