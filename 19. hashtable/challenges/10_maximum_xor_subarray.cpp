/*
Given an array of n integers, find subarray whose xor is maximum. A subarray is a contiguous part of array.
Input Format

First line contains single integer n (1<=n<=1000). Next line contains n space separated integers
Constraints

1 <= n <= 1000
1 <= A[i] <=1000
Output Format

Print xor of the subarray whose xor of all elements in subarray is maximum over all subarrays.
Sample Input

4
1 2 3 4

Sample Output

7
*/
#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int maxi = 0, newVal;
    int k;
    for (int i = 0; i < n; i++)
    {
        k = 0; //U have to initialise the value as 0 for xor of the subarray
        for (int j = i; j < n; j++)
        { //since you have to include the value of ith element also thus your inner loop shall start from i AND NOT i+1
            //cout<<i<<" "<<j<< " ";
            //cout<<a[i]<<" "<< a[j]<<" XOR ";
            k = k ^ a[j];        // we store and update the xor in k for the subarray.
                                 // cout<<newVal<<"\n";
            maxi = max(maxi, k); //if the xor for the subarray[i,j] is more than the latest xor in maxi then update maxi.
        }
    }
    cout << maxi;
}