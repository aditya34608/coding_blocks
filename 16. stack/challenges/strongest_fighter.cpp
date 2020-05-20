/*


There is a group of MMA fighters standing together in a line. Given the value of their strengths, find the strength of the strongest fighter in continuous sub-groups of size k.
Input Format

First line contains an integer N, the number of fighters Followed by N integers where i'th integer denotes the strength of i'th fighter. Next line contains the size of sub-group k
Constraints

1<=N<=10^7
1<=k<=N
1 <= Ai <= 100000
Output Format

Space separated integers in a single line denoting strength of strongest fighters in the groups.
Sample Input

5
1 3 1 4 5
3

Sample Output

3 4 5

Explanation

First sub-group: 1 3 1 --> Max strength is 3
Second sub-group: 3 1 4 --> Max strength is 4
Third sub-group: 1 4 5 --> Max strength is 5

*/
#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int k;
    cin>>k;
    int m=0;
    int i=0;
    while(i<k)
    {
        if(a[m]<a[i])
        m=i;

        i++;
    }
    cout<<a[m]<<" ";
    int j=0;
    for(int i=k;i<n;i++,j++)
    {
        if(a[m]<=a[i])
        {
            m=i;
            cout<<a[m]<<" ";
            continue;
        }  
        else if(a[m]>a[i])
        {
            if(m>j)
            cout<<a[m]<<" ";

            else 
            {
                m=j+1;
                for(int x=j+1;x<=i;x++)
                {
                    if(a[x]>a[m])
                    {
                        m=x;
                    }
                }
                cout<<a[m]<<" ";
            }
        }
    }
    return 0;
}