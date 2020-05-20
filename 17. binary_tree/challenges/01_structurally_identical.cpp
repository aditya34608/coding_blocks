/*
Given two trees check if they are structurally identically. Structurally identical trees are trees that have same structure. They may or may not have the same data though.
Input Format

Enter the values of all the nodes in the binary tree in pre-order format where true suggest the node exists and false suggests it is NULL
Constraints

1 <= N <= 10^4
Output Format

Display the Boolean result
Sample Input

10 true 20 true 40 false false true 50 false false true 30 true 60 false false true 73 false false
10 true 20 true 40 false false true 50 false false true 30 true 60 false false true 73 false false

Sample Output

true

Explanation

The given two trees have the exact same structure and hence we print true.

*/
#include<iostream>

using namespace std;

int x=0;

class node{
public:
    node* right = NULL;
    node* left = NULL;
    int data;
    
    node(int d){
        data = d;
    }
};

node* insert(node* &root){
    if(x == 0){
        int k;
        cin >> k;
        x++;
        root = new node(k);
        root -> left = insert(root -> left);
        root -> right = insert(root -> right);
        return root;
    }
    string s = "abc";
    cin >> s;
    if(s != "abc"){
        if(s == "true"){
        int d;
        cin >> d;
        node* nn = new node(d);
        nn -> left = insert(nn -> left);
        nn -> right = insert(nn -> right);
        return nn;
        }
        else{
            return root;
        }
    }
    return root;
}

void print(node* root){
    if(root == NULL){
        return;
    }
    cout << root -> data << " ";
    print(root -> left);
    print(root -> right);
    return;
}

bool check(node* root1, node* root2){
    if(root1 == NULL and root2 == NULL){
        return true;
    }
    else if(root1 == NULL or root2 == NULL){
        return false;
    }
    return check(root1 -> right, root2 -> right) &&  check(root1 -> left, root2 -> left);
}

int main(){
    node* root1 = NULL;
    node* root2 = NULL;
    x = 0;
    insert(root1);
    x = 0;
    insert(root2);
    if(check(root1, root2)){
        cout << "true";
    }
    else{
        cout << "false";
    }
}