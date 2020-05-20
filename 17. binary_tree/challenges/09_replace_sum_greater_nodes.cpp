/*
Given a binary search tree, replace each nodes' data with the sum of all nodes' which are greater or equal than it. Include the current node's data also.
Input Format

The first line contains a number n showing the length of the inorder array of BST. The next line contains n integers denoting the elements of the array.
Constraints

2 ≤ N ≤ 10^3
Output Format

Print the preorder traversal of the new tree.
Sample Input

7
20 30 40 50 60 70 80

Sample Output

260 330 350 300 150 210 80

Explanation

The original tree looks like

            50             
        /        \                
      30          70
    /    \       /   \ 
  20    40      60    80

We are supposed to replace the elements by the sum of elements larger than it.
80 being the largest element remains unaffected .
70 being the second largest element gets updated to 150 (70+80)
60 becomes 210 (60 + 70 + 80)
50 becomes 260 (50 + 60 + 70 + 80)
40 becomes 300 (40 + 50 + 60 + 70 + 80)
30 becomes 330 (30 + 40 + 50 + 60 + 70 + 80)
20 becomes 350 (20 + 30 + 40 + 50 + 60 + 70 + 80)

The new tree looks like

           260             
        /        \                
     330         150
    /    \       /   \ 
  350    300   210    80

The Pre-Order traversal (Root->Left->Right) looks like :
260 330 350 300 150 210 80.

*/
#include <iostream>

using namespace std;

class node
{
public:
  int data;
  node *right;
  node *left;

  node(int d)
  {
    data = d;
    right = left = NULL;
  }
};

node *build(int *in, int s, int e)
{
  if (s > e)
  {
    return NULL;
  }
  int mid = (s + e) / 2;
  node *root = new node(in[mid]);
  root->left = build(in, s, mid - 1);
  root->right = build(in, mid + 1, e);
  return root;
}

void preorder(node* root){
  if (root == NULL){
    return;
  }
  cout << root -> data << " ";
  preorder(root -> left);
  preorder(root -> right);
}

void change(node* root){
  static int k = 0;
  
}