//6
// 3 10 5 25 2 8

#include <iostream>
#include <math.h>
#include <climits>

using namespace std;

class TrieNode
{
public:
    TrieNode *left;
    TrieNode *right;
};

void insert(int n, TrieNode *head)
{
    TrieNode *curr = head;

    // so that bit size is no more than 32 bits digit
    for (int i = 31; i >= 0; i--)
    {
        int bit = (n >> i) & 1;
        if (bit == 0)
        {
            if (curr->left == NULL)
            {
                curr->left = new TrieNode();
            }
            curr = curr->left;
        }
        else
        {
            if (curr->right == NULL)
            {
                curr->right = new TrieNode();
            }
            curr = curr->right;
        }
    }
}

int find_max_xor_pair(TrieNode *head, int *arr, int n, int el)
{
    int max_xor = INT_MIN;
    TrieNode *curr = head;
    int value = el;
    int curr_xor = 0;
    for (int j = 31; j >= 0; j--)
    {
        int b = (value >> j) & 1;
        if (b == 0)
        {
            if (curr->right != NULL)
            {
                curr = curr->right;
                curr_xor += (int)pow(2, j);
            }
            else
            {
                curr = curr->left;
            }
        }
        else
        {
            if (curr->right != NULL)
            {
                curr = curr->right;
                curr_xor += (int)pow(2, j);
            }
            else
            {
                curr = curr->right;
            }
        }
    }
    if (curr_xor > max_xor)
    {
        max_xor = curr_xor;
    }
    return max_xor;
}

int main()
{
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    int *arr = new int[n]();
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    TrieNode *head = new TrieNode();
    int result = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        insert(arr[i], head);
        int x = find_max_xor_pair(head, arr, n, arr[i]);
        result = (result < x) ? x : result;
    }
    cout << result << "\n";
    return 0;
}