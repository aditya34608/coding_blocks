#include <iostream>
#include <unordered_set>

using namespace std;

bool check_subarray_with_sum_zero(int *arr, int n)
{
    unordered_set<int> s;
    int prefix = 0;
    for (int i = 0; i < n; i++)
    {
        prefix += arr[i];
        if (prefix == 0 or s.find(prefix) != s.end())
        {
            return true;
        }
        s.insert(prefix);
    }
    return false;
}

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    bool b = check_subarray_with_sum_zero(arr, n);
    if (b == 0)
    {
        cout << "No\n";
    }
    else
    {
        cout << "Yes\n";
    }
    return 0;
}
