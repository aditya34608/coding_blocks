/*
Given a binary tree. Print the zig zag order i.e print level 1 from left to right, level 2 from right to left and so on. 
This means odd levels should get printed from left to right and even levels should be printed from right to left. 
Each level should be printed at a new line.

Input Format

Enter the values of all the nodes in the binary tree in pre-order format where true suggest the node exists and false suggests it is NULL

Constraints

None
Output Format

Display the values in zigzag level order in which each value is separated by a space
Sample Input

10 true 20 true 40 false false true 50 false false true 30 true 60 false false true 73 false false

Sample Output

10 30 20 40 50 60 73 
*/
#include <iostream>

using namespace std;

class node{
public:
    string data;
    node*left;
    node*right;
    node(string d){
        data=d;
        left=NULL;
        right=NULL;
    }
};

node*buildtree(){
    string str;
    cin >> str;

    if (str == "false"){
        return NULL;
    }
    if(str == "true"){
        string d;
        cin >> d;
        node*root = new node(d);
        root -> left = buildtree();
        root -> right = buildtree();
        return root;
    }
    node* root = new node(str);
    root -> left = buildtree();
    root -> right = buildtree();
    return root;
}

int height(node* root){
    if(root == NULL){
        return 0;
    }
    int lh = height(root -> left);
    int rh = height(root -> right);
    return max(lh,rh) + 1;
}

void kthlevel(node* root, int k){
    if(root == NULL){
        return;
    }
    if(k == 0){
        cout << root -> data << " ";
    }
    kthlevel(root -> left, k-1);
    kthlevel(root -> right, k-1);
}

void kthlevel1(node* root, int k){
    if(root == NULL){
        return;
    }

    if(k == 0){
        cout << root -> data <<" ";
    }
    kthlevel1(root -> right, k-1);
    kthlevel1(root -> left, k-1);
}

void zigzag(node* root){
    int h = height (root);
    for(int i=0; i<h; i++)
    {
        if(i%2 == 0)
        {
            kthlevel(root, i);
        }
        else if(i%2 != 0)
        {
          kthlevel1(root, i);
        }
    }
}

int main(){
   node* root = buildtree();
   zigzag(root);
}