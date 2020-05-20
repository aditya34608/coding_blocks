#include <iostream>
#include <queue>
#include <climits>

using namespace std;

class Node{
public:
    int data; 
    Node* left;
    Node* right;

    Node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};

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

//accept old root and data and return the new root
Node* insertinbst(Node* root, int data){
    //base case
    if (root == NULL){
        return new Node(data);
    }
    //recursion
    if (data <= root -> data){
        root -> left = insertinbst(root -> left, data);
    }
    else{
        root -> right = insertinbst(root -> right, data);
    }
    return root;
}

Node* Build(){
    //read list till -1 and add to bst
    int d;
    cin >> d;
    Node* root = NULL;
    while (d != -1){
        root = insertinbst(root, d);
        cin >> d;
    }
    return root;
}

bool isbst(Node* root, int minv = INT_MIN, int maxv = INT_MAX){
    if (root == NULL){
        return true;
    }
    if (root -> data >= minv && root -> data <= maxv && isbst(root -> left, minv, root -> data) && isbst(root -> right, root -> data, maxv)){
        return true;
    }
    return false;
}

int main(){
    Node* root = Build();
    if (isbst(root)){
        cout << "yes";
    }
    else{
        cout << "no";
    }
    return 0;
}