//sum of all nodes

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

class HBPair{
    public:
        int height;
        bool balance;
};

HBPair heightbalance(Node* root){
    HBPair P;
    if (root == NULL){
        P.height = 0;
        P.balance = true;
        return P;
    }
    //recursive
    HBPair left = heightbalance(root -> left);
    HBPair right = heightbalance(root -> right);

    P.height = max(left.height, right.height) + 1;

    if (abs(left.height - right.height) <= 1 && left.balance && right.balance){
        P.balance = true;
    }
    else{
        P.balance = false;
    }
    return P;
}

int main(){
    Node* root = buildTree();
    if (heightbalance(root).balance){
        cout << "Balanced" << "\n";
    }
    else{
        cout << "Not Balanced" << "\n";
    }
    return 0;
}