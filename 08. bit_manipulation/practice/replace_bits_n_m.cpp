
/*
Replace Bits in N by M
You're given two 32-bit numbers, N and M, and two bit positions,
i and j. Write a method to set all bits between i and j in N equal
to M (e.g., M becomes a substring of N located at i and starting at j).

Example:
Input: N = 10000000000;
M = 10101, i = 2, j = 6;
Output: N = 10001010100;
*/
#include <bits/stdc++.h>

using namespace std;

int clearRangeItoJ(int n, int i, int j){
    int ones = (~0);
    int a = ones << (j+1);
    int b = (1 << i) - 1;
    int mask = a | b;
    int ans = n & mask;
    return ans;
}

int replaceBits(int n, int m, int i, int j){
    int n1 = clearRangeItoJ(n, i, j);
    int ans = n1 | (m << i);
    return ans;
}

int main(){
    int n, i, j, m;
    cin >> n >> i >> j >> m;
    cout << replaceBits(n, m, i, j);
    return 0;
}
