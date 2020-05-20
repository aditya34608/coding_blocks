#include <iostream>

using namespace std;

class Node{
    public:
        int data;
        Node* right;
        Node* left;
        Node (int d){
            data = d;
            left = NULL;
            right = NULL;
        }
};

Node* buildTree(){
    int d;
    cin >> d;
    if (d == -1){
        return NULL;
    }
    Node* root = new Node(d);
    root -> left = buildTree();
    root -> right = buildTree();
} 

void print(Node* root){
    if (root == NULL){
        return;
    }
    //print root first followed by subtrees
    cout << root -> data << " ";
    print(root -> left);
    print(root -> right);
}

//height of the tree
int height(Node* root){
    if (root == NULL){
        return 0;
    }
    int ls = height(root -> left);
    int rs = height(root -> right);
    return max(ls, rs) + 1;
}

void printklevel(Node* root, int k){
    if (root == NULL){
        return;
    }
    if (k == 1){
        cout << root -> data << " ";
        return;
    }
    printklevel(root -> left, k-1);
    printklevel(root -> right, k-1);
}

void printalllevel(Node* root){
    int H = height(root);
    for (int i=1; i<= H; i++){
        printklevel(root, i);
        cout << "\n";
    }
}

int main(){
    Node* root = buildTree();
    printklevel(root, 3);
    cout << "\n";
    printalllevel(root);
}