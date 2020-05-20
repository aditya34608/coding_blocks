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

class Pair{
    public:
        int height;
        int diameter;
};

Pair fastdiameter(Node* root){
    Pair p;
    if (root == NULL){
        p.diameter = p.height = 0;
        return p;
    }
    //otherwise
    Pair left = fastdiameter(root -> left);
    Pair right = fastdiameter(root -> right);

    p.height = max(left.height, right.height) + 1;
    p.diameter = max(left.height + right.height, max(left.diameter, right.diameter));
    return p;
}

int main(){
    Node* root = buildTree();
    Pair p = fastdiameter(root);
    cout << p.height << "\n";
    cout << p.diameter << "\n"; 
    return 0;
}