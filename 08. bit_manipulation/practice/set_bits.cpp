#include <bits/stdc++.h>

using namespace std;

bool isOdd(int n){
    return (n & 1);
}

int getBit(int n, int i){
    int mask = (1 << i);
    int bit = (n & mask) > 0 ? 1 : 0;

    return bit;
}

int setBit(int n, int i){
    int mask = (1 << i);
    int ans = (n | mask);

    return ans;
}

void clearBit(int &n, int i){
    int mask = ~(1 << i);
    n = n & mask;
}

void updateBit(int &n, int i, int v){
    int mask = ~(1 << i);
    int cleared_n = n & mask;
    n = cleared_n | (v << i);
}

int clearLastBits(int n, int i){
    int mask = (-1 << i);
    return n & mask;
}

int rangeBits(int n, int i, int j){
    int ones = (~0);
    int a = ones << (j+1);
    int b = (1 << i)-1;
    int mask = a | b;
    int ans = n & mask;
    return ans;   
}

int main(){
    int n, i, j;
    cin >> n;
    cin >> i;
    cin >> j;

    //cout << isOdd(n) << "\n";
    //cout << getBit(n, i) << "\n";
    //cout << setBit(n, i) << "\n";
    //clearBit(n,i);
    //updateBit(n, 2, 0);
    //updateBit(n, 3, 1);
    //cout << clearLastBits(n, i) << "\n";
    //cout << n << "\n";

    cout << rangeBits(n, i, j) << "\n";
    return 0;
}
