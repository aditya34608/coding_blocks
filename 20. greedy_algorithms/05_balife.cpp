// https://www.spoj.com/problems/BALIFE/

#include <iostream>
using namespace std;
int main()
{
    int arr[9000];
    int n, i, val, diff;

    while (1)
    {
        int max_load = 0, load = 0, diff;
        cin >> n;
        if (n == -1)
        {
            break;
        }
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            load += arr[i];
        }

        if (load % n != 0)
        {
            cout << -1 << "\n";
            continue;
        }

        //find the load that is to be dividede equally
        load = load / n;
        diff = 0;
        
        // greedy step
        for (int i = 0; i < n; i++)
        {
        // find the difference btw find load to be assigned and current load
            diff += (arr[i] - load);
            int ans = max(diff, -diff);
            max_load = max(max_load, ans);
        }
        cout << max_load << "\n";
    }
    return 0;
}