//creating tree from preorder and inorder traversal

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

Node* createTree(int* in, int* pre, int s, int e){
    static int i = 0;
    //base case
    if (s > e){
        return NULL;
    }
    //recursive case
    Node* root = new Node(pre[i]);
    int index = -1;
    for (int j = s; s <= e; j++){
        if (in[j] == pre[i]){
            index = j;
            break;
        }
    }
    i++;

    root -> left = createTree(in, pre, s, index - 1);
    root -> right = createTree(in, pre, index + 1, e);
    return root;
}

int main(){
    int in[] = {3, 2, 8, 4, 1, 6, 7, 5};
    int pre[] = {1, 2, 3, 4, 8, 5, 6, 7};
    int n = sizeof(in)/ sizeof(int);
    
    Node* root = createTree(in, pre, 0, n-1);
    bfs(root);
    return 0;
}