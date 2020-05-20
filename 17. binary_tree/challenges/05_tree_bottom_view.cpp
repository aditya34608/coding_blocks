/*
Given a binary tree , print the nodes in left to right manner as visible from below the tree
Input Format

Level order input for the binary tree will be given.
Constraints

No of nodes in the tree can be less than or equal to 10^7
Output Format

A single line containing space separated integers representing the bottom view of the tree
Sample Input

1 2 3 4 5 6  -1 -1 -1 -1 -1 -1 -1

Sample Output

4 2 6 3

Explanation

The tree looks like

                 1
              /      \
           2           3
        /     \       /
       4       5     6

*/
#include<iostream>
#include<queue>

using namespace std;

int max1=0,min1=0;

class node{
public:
    int data;
    node *left;
    node*right;

    node(int d)
    {
        data = d;
        right = NULL;
        left = NULL;
    }
};

void traverse(node* root,vector<pair<node*,int> > &pos,vector<pair<node*,int> > &neg, int level, int k){
    if(root == NULL)
        return;
    if(k >= 0 && level >= pos[k].second){ 
        pair<node*,int> temp;
        temp.first = root;
        temp.second = level;
        pos[k] = temp;
    }
    if(k<0 && level > neg[(-1)*k].second){ 
        pair<node*,int> temp;
        temp.first = root;
        temp.second = level;
        neg[(-1)*k] = temp;
    }
    if(max1 < k)
        max1 = k;
    if(min1 > k)
        min1 = k;
    traverse(root -> left, pos, neg, level+1, k-1);
    traverse(root -> right, pos, neg, level+1, k+1);
}

int main() {
    int d;
    vector<pair<node*, int> > pos(100000);
    pair<node*,int> temp;
    temp.first = NULL;
    temp.second = 0;
    pos.push_back(temp);
    temp.second = 0;
    vector<pair<node*,int> > neg(100000);
    neg.push_back(temp);
    neg.push_back(temp);
    
    cin >> d;

    node*root = new node(d);
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        node*f = q.front();
        q.pop();
        int c1,c2;
        cin >> c1 >> c2;
        if(c1 != -1){
            f -> left = new node(c1);
            q.push(f -> left);
        }
        if(c2 != -1){
            f -> right = new node(c2);
            q.push(f -> right);
        }
    }
    traverse(root, pos, neg, 0, 0);
    int negsize = neg.size()-1;
    int possize = pos.size()-1;
    for(int i=(min1*(-1)); i>=1; i--)
        cout << neg[i].first -> data << " ";
    for(int i=0; i <= max1; i++)
        cout << pos[i].first -> data << " ";
	return 0;
}