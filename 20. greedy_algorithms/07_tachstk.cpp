// https://www.codechef.com/problems/TACHSTCK

#include <iostream>
#include <algorithm>

using namespace std;
int main()
{
    int n, d, l[100000];
    cin >> n >> d;
    for (int i = 1; i <= n; i++)
    {
        cin >> l[i];
    }

    sort(l, l + n);

    int pos = 0;
    int res = 0;

    while (pos < n)
    {
        if (abs(l[pos] - l[pos + 1]) <= d)
        {
            res++;
            pos += 2;
        }
        else
        {
            pos++;
        }
    }
    cout << res << "\n";
    return 0;
}