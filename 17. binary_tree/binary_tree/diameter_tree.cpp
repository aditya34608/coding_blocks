#include <iostream>
#include <queue>

using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;
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

void bfs(Node *root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* f = q.front();
        if(f == NULL){
            cout << "\n";
            q.pop();
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout << f -> data << "," ;
            q.pop();

            if(f -> left){
                q.push(f -> left);
            }
            if(f -> right){
                q.push(f -> right);
            }
        }
    }
    return;
}

int height(Node* root){
    if (root == NULL){
        return 0;
    }
    int ls = height(root -> left);
    int rs = height(root -> right);
    return max(ls, rs) + 1;
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

int diameter(Node* root){
    if (root == NULL){
        return 0;
    }
    int h1 = height(root -> left);
    int h2 = height(root -> right);
    int op1 = h1 + h2;
    int op2 = diameter(root -> left); //preorder travesal
    int op3 = diameter(root -> right);
    return max(op1, max(op2, op3));
}

int main(){
    Node* root = buildTree();
    cout << diameter(root) << "\n";
    return 0;
}