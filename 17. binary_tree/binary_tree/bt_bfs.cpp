#include <iostream>
#include <queue>

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

void bfs(Node *root){
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        Node* f = q.front();
        cout<<f->data<<" ";
        q.pop();

        if(f->left){
            q.push(f->left);
        }
        if(f->right){
            q.push(f->right);
        }
    }
    return;
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

int main(){
    Node* root = buildTree();
    bfs(root);
    return 0;
}