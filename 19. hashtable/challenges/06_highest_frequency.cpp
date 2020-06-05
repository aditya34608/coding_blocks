/*
Given an array find the number which comes with maximum frequency. It must work in O(n) time complexity.
Input Format

Enter the size of the array N and add N more numbers and store in an array
Constraints

1 <= N <= 10^7
Output Format

Display the number with the maximum frequency.
Sample Input

5
1 2 2 2 3

Sample Output

2

Explanation

2 has the highest frequency in the array i.e. 3.

*/

#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    unordered_map<int, int> h{0};
    for (int i = 0; i < n; i++)
    {
        h[a[i]]++;
    }
    int res = -1;
    int maxcount = 0;
    for (auto x : h)
    {
        if (x.second >= maxcount)
        {
            res = x.first;
            maxcount = x.second;
        }
    }
    cout << res;
}