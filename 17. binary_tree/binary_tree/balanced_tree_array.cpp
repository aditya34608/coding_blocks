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

Node* buildTreeArray(int *a, int s, int e){
    //base case
    if (s > e){
        return NULL;
    }
    //recursive
    int mid = (s + e) / 2;
    Node* root = new Node(a[mid]);
    root -> left = buildTreeArray(a, s, mid - 1);
    root -> right = buildTreeArray(a, mid+1, e);
    return root;
}


int main(){
    int a[] = {1, 2, 3, 4, 5, 6, 7};
    int n = 7;
    Node* root = buildTreeArray(a, 0, n-1);
    bfs(root);
    return 0;
}