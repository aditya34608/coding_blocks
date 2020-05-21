/*
Given K sorted arrays each with N elements merge them and output the sorted array
Input Format

First line contains 2 space separated integers K and N.
K is number of arrays.
N is number of elements in each array.
Next K lines contain N space separated integers each where ith line denotes the element of ith sorted array.
Constraints

Elements of array <= |10^15|
N <= 10^5
K <= 10
Output Format

Single line consisting of space separated numbers
Sample Input

3 4
1 3 5 7
2 4 6 8
0 9 10 11

Sample Output

0 1 2 3 4 5 6 7 8 9 10 11

Explanation

If we were to combine all the arrays into one and then sort it , the output would be as above.
*/

#include <bits/stdc++.h>
using namespace std;
#define pp pair<int, pair<int, int>> //In this pair, first int represents the element, next two int represents its position in 2d vector ie. i,j

vector<int> mergekarray(vector<vector<int>> arr, int k)
{
    priority_queue<pp, vector<pp>, greater<pp>> pq; //Min Heap is made according to the first element of the pair which is the vector element at i,j
    vector<int> oarr;
    for (int i = 0; i < k; i++)
        pq.push({arr[i][0], {i, 0}}); //Pushing the first element of all K sorted arrays in the priority queue
    //Processing and pushing the remaining elements
    while (!pq.empty())
    {
        pp front = pq.top();
        pq.pop();
        oarr.push_back(front.first);
        int id = front.second.first;
        int j = front.second.second;
        if (j + 1 < arr[id].size())
            pq.push({arr[id][j + 1], {id, j + 1}});
    }
    return oarr;
}

int main()
{
    int k, n;
    cin >> k >> n;
    vector<vector<int>> arr(k, vector<int>(n)); //Storing k sorted arrays in a 2d vector
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];
    }
    vector<int> output = mergekarray(arr, k);
    for (auto i : output)
        cout << i << " ";
    return 0;
}