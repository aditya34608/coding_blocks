// https://www.spoj.com/problems/BAISED/

#include <iostream>
#include <cstring>

using namespace std;

int abs(int i, int j)
{
    if (i - j > 0)
    {
        return i - j;
    }
    return j - i;
}

int main()
{
    int arr[100000] = {0};
    int t;
    cin >> t;

    while (t--)
    {
        memset(arr, 0, sizeof(arr));
        string name;
        int n, rank;
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            cin >> name >> rank;
            arr[rank]++;
        }

        //greedy approach
        int act_rnk = 1;
        int sum = 0;
        for (int i = 1; i <= n; i++)
        {
            while (arr[i])
            {
                sum += abs(act_rnk, i);
                arr[i]--;
                act_rnk++;
            }
        }
        cout << sum << "\n";
    }
    return 0;
}