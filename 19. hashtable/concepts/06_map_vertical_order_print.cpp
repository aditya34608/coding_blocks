#include <iostream>
#include <map>
#include <vector>
#include <unordered_map>

using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        data = d;
        left = right = NULL;
    }
};

//we need to pass by value otherwise m will one more copy of map
void vertical_order_print(node *root, int dist, map<int, vector<int>> &m)
{
    //base case
    if (root == NULL)
    {
        return;
    }

    //otherwise
    m[dist].push_back(root->data);
    vertical_order_print(root->left, dist - 1, m);
    vertical_order_print(root->right, dist + 1, m);
    return;
}

int main()
{
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);

    root->right->left = new node(6);
    root->right->right = new node(7);

    root->right->right->right = new node(9);
    root->left->right->right = new node(8);

    map<int, vector<int>> m;

    int dist = 0;
    vertical_order_print(root, dist, m); //will traverse the map

    for (auto p : m)
    {
        cout << p.first << " -> ";
        for (int l : p.second)
        {
            printf("%d, ", l);
        }
        cout << "\n";
    }

    return 0;
}