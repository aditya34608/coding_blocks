/*
Given an array, the task is to calculate the sum of lengths of contiguous subarrays having all elements distinct
Input Format

An integer n denoting size of array followed by n integers
Constraints

1<=N<=10^5
Output Format

The answer mod 10^9+7
Sample Input

3
1 2 3

Sample Output

10

Explanation

{1, 2, 3} is a subarray of length 3 with distinct elements. Total length of length three = 3. {1, 2}, {2, 3} are 2 subarray of length 2 with distinct elements. Total length of lengths two = 2 + 2 = 4 {1}, {2}, {3} are 3 subarrays of length 1 with distinct element. Total lengths of length one = 1 + 1 + 1 = 3 Sum of lengths = 3 + 4 + 3 = 10

*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    set<int> s;

    int N;

    cin >> N;
    int a[N];

    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
    }

    int i = 0, j = 0, sum = 0;
    for (int i = 0; i < N; i++)
    {
        while (j < N && s.find(a[j]) == s.end())
        {
            s.insert(a[j]);
            j++;
        }
        sum += ((j - i + 1) * (j - i)) / 2;
        s.erase(a[i]);
    }
    cout << sum;
    return 0;
}