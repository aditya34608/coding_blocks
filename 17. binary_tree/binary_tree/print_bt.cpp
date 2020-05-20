//preorder postorder inorder printing of bt

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
    return root;
} 

//preorder print
void print_pre(Node* root){
    if (root == NULL){
        return;
    }
    cout << root -> data << " ";
    print_pre(root -> left);
    print_pre(root -> right);
}

//inorder print
void print_in(Node* root){
    if (root == NULL){
        return;
    }
    print_in(root -> left);
    cout << root -> data << " ";
    print_in(root -> right);
}

//postorder print
void print_post(Node* root){
    if (root == NULL){
        return;
    }
    print_post(root -> left);
    print_post(root -> right);
    cout << root -> data << " ";
}
int main(){
    Node* root = buildTree();

    //preorder
    print_pre(root);
    cout << "\n";

    //inorder
    print_in(root);
    cout << "\n";

    //postorder
    print_post(root);
    cout << "\n";
    return 0;
}