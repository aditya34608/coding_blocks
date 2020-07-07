// https://www.spoj.com/problems/EXPEDI/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool compare(pair<int, int> p1, pair<int, int> p2)
{
    return p1.first > p2.first;
}

int main()
{
    int t, n, l, p, L, P, prev = 0, flag = 0, ans = 0;
    cin >> t;
    while (t--)
    {
        vector<pair<int, int>> v;
        priority_queue<int> pq;
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            cin >> l >> p;
            v.push_back(make_pair(l, p));
        }
        //sort the cities according to their location
        sort(v.begin(), v.end(), compare);

        cin >> L >> P;

        for (int i =0; i<n; i++){
            v[i].first = L - v[i].first;
        }

        //update the distamce of the fuel from truck
        int x = 0; //current city
        while (x < n)
        {
            // if we have enough to reach next city
            if (P >= (v[x].first) - prev)
            {
                P = P - (v[x].first - prev);
                pq.push(v[x].second);
                prev = v[x].first;
            }
            else
            {
                //check if you have visited fuelling station in priority queue
                if (pq.empty())
                {
                    flag = 1;
                    break;
                }

                //refuel truck with feul station with higher capacity
                P += pq.top();

                //remove that fuel station from queue
                pq.pop();
                ans = ans + 1;
                continue;
            }
            x++;
        }
        //actually travelled through n fuel stations
        //fuel left to reach town after last station
        if (flag == 1)
        {
            cout << -1 << "\n";
            continue;
        }

        //otherwise
        L = L - v[n - 1].first;
        if (P >= L)
        {
            cout << ans << "\n";
            continue;
        }

        //otherwise
        while (P < L)
        {
            if (pq.empty())
            {
                flag = 1;
                break;
            }

            P += pq.top();
            pq.pop();
            ans = ans + 1;
        }

        if (flag == 1)
        {
            cout << -1 << "\n";
            continue;
        }
        cout << ans << "\n";
    }

    return 0;
}