// https://www.spoj.com/problems/DEFKIN/

#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int t, w, x, y, h, n;
    cin >> t;
    while (t--)
    {
        int x[40010], y[40010];
        cin >> w >> h >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> x[i] >> y[i];
        }

        //sort
        sort(x, x + n);
        sort(y, y + n);

        int dx = x[0] - 1;
        int dy = y[0] - 1;

        for (int i = 1; i < n; i++)
        {
            dx = max(dx, x[i] - x[i - 1] - 1);
            dy = max(dy, y[i] - y[i - 1] - 1);
        }

        //corner case (last tower to grid end)
        dx = max(dx, w - x[n - 1]);
        dy = max(dy, h - y[n - 1]);

        cout << dx * dy << "\n";
    }

    return 0;
}