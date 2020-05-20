/*
Given preorder and inorder create the tree
Input Format

Enter the size of the preorder array N then add N more elements and store in the array denoting the preorder traversal of the tree. Then enter the size of the inorder array M and add M more elements and store the inorder traversal of the array.
Constraints

1 <= N, M <= 10^4
Output Format

Display the tree using a modified preorder function. For each node , first print its left child's data , then the data of the root itself , then the data of its right child. Do this for each node in a new line in preorder manner. If one of the children does not exist print END in its place. Refer to the sample testcase.
Sample Input

3
1 2 3
3
3 2 1

Sample Output

2 => 1 <= END
3 => 2 <= END
END => 3 <= END

Explanation

The above tree looks like

             1
           /
         2
       /
     3


*/
#include<iostream>
using namespace std;

class node{
public:
    int data;
    node *left;
    node *right;
    
    node (int d){
        data = d;
        left = right = NULL;
    }
};

node* preIno(int *inorder, int * preorder, int s, int e){
    static int i = 0;
    
    //base case
    if(s > e){
        return NULL;
    }    
    
    //rec
    node *root = new node(preorder[i]);
    int index = -1;
    for(int j=s; j<=e; j++)
        if(inorder[j] == preorder[i]){
            index=j;
            break;
        }
    ++i; //moving ahead in preorder array;

    root -> left = preIno(inorder, preorder, s, index-1);
    root -> right = preIno(inorder, preorder, index+1, e);
    return root;
}

void printStyle(node *root){
    if(root == NULL)
        return ;
    if(root -> left == NULL)
        cout << "END => ";
    else
        cout << root -> left -> data<<" => ";
    cout << root -> data;    
    if(root -> right == NULL)
        cout << " <= END" << "\n";
    else
        cout << " <= " << root -> right -> data <<"\n";
    
    printStyle(root -> left);
    printStyle(root -> right);

}

int main(){
    int n;
    cin >> n;
    int preorder[n];
    for(int i = 0; i<n; i++)
        cin >> preorder[i];
    int m;
    cin >> m;
    int inorder[m];
    for(int i=0; i<m; i++)
        cin >> inorder[i];
    node *root = preIno(&inorder[0], &preorder[0], 0, n-1);
    printStyle(root);         
	return 0;
}