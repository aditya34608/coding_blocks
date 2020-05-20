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

void print(Node* root){
    if (root == NULL){
        return;
    }
    //print root first followed by subtrees
    cout << root -> data << " ";
    print(root -> left);
    print(root -> right);
}

int count(Node* root){
    if (root == NULL){
        return 0;
    }
    return 1 + count(root -> left) + count(root -> right);
}

int sum(Node* root){
    if (root == NULL){
        return 0;
    }
    return (root -> data + sum(root -> left) + sum(root -> right));
} 

int main(){
    Node* root = buildTree();
    cout << count(root) << "\n";
    cout << sum(root) << "\n";
    return 0;
}