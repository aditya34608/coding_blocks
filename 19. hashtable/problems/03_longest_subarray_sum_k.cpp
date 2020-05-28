#include <iostream>
#include <unordered_map>

using namespace std;

int longest_subarray_sum_k(int *arr, int n, int k)
{
    unordered_map<int, int> mp;
    int prefix = 0;
    int length = 0;
    for (int i = 0; i < n; i++)
    {
        prefix += arr[i];
        if (prefix == k)
        {
            length = max(length, i + 1);
        }
        if (mp.find(prefix - k) != mp.end())
        {
            length = max(length, i - mp[prefix - k]);
        }
        else
        {
            mp[prefix] = i;
        }
    }
    return length;
}

int main()
{
    int n, k;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cin >> k;
    cout << longest_subarray_sum_k(arr, n, k) << "\n";
}