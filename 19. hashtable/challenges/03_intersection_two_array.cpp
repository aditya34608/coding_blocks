/*
Take as input N, the size of array. Take N more inputs and store that in an array. 
Take N more inputs and store that in another array. 
Write a function which gives the intersection of two arrays in an ArrayList of integers and Print the ArrayList.

Input Format

First line contains N denoting the size of the two arrays. 
Second line contains N space separated integers denoting the elements of the first array. Third line contains N space separated integers denoting the elements of the second array.

Constraints

Length of Arrays should be between 1 to 100000.

Output Format

Display the repeating elements in a comma separated manner enclosed in square brackets. 
The numbers should be sorted in increasing order.

Sample Input

7
1 2 3 1 2 4 1
2 1 3 1 5 2 2

Sample Output

[1, 1, 2, 2, 3]

Explanation

Check which integer is present in both the arrays and add them in an array.
Print this array as the ans.

*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void findIntersection(int *arr1, int *arr2, int n1, int n2)
{

    unordered_map<int, int> m;
    for (int i = 0; i < n1; i++)
    {

        m[arr1[i]]++;
        //cout<<arr1[i]<<" ";
    }
    vector<int> v;
    for (int i = 0; i < n2; i++)
    {
        if (m.count(arr2[i]) == 1)
        {
            v.push_back(arr2[i]);
            m[arr2[i]]--;
            if (m[arr2[i]] == 0)
                m.erase(arr2[i]);
        }
    }
    sort(v.begin(), v.end());
    cout << "[";
    for (int i = 0; i < v.size() - 1; i++)
    {
        cout << v[i] << ", ";
    }
    cout << v[v.size() - 1] << "]";
    cout << endl;
}
int main()
{
    int n;
    cin >> n;
    int arr1[n], arr2[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr1[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> arr2[i];
    }
    findIntersection(arr1, arr2, n, n);
}