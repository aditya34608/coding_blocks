#include <iostream>
#include <queue>

using namespace std;

//template <typename T> //for generic
class Node{
public:
    int data; //T data; 
    Node* left;
    Node* right;

    Node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};

void inorder(Node* root){
    if (root == NULL){
        return;
    }    
    inorder(root -> left);
    cout << root -> data << ",";
    inorder(root -> right);
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

bool search(Node* root, int data){
    if (root == NULL){
        return false;
    }
    if (root -> data == data){
        return true;
    }
    //recursively search in left and right subtrees
    if (data <= root -> data){
        return search(root -> left, data);
    }
    else{
        return search(root -> right, data);
    }
}

Node* deleteinbst(Node* root, int data){
    if (root == NULL){
        return NULL;
    }
    else if (data < root -> data){
        root -> left = deleteinbst(root -> left, data);
        return root;
    }
    else if (data == root -> data){
        // Condition 1 : 0 Child
        if (root -> left == NULL && root -> right == NULL){
            delete root;
            return NULL;
        }
        // Condition 2 : 1 Child
        if (root -> left != NULL &&  root -> right == NULL){
            Node* temp = root -> left;
            delete root;
            return temp;
        } 
        if (root -> left == NULL && root -> left != NULL){
            Node* temp = root -> right;
            delete root;
            return temp;
        } 
        // Condition 3 : 2 Child
        //find inorder sucessor from right subtree
        Node* replace = root -> right;
        while(replace -> left != NULL){
            replace = replace -> left;
        }
        root -> data = replace -> data;
        root -> right = deleteinbst(root -> right, replace -> data);
        return root; 
    }
    else{
        root -> right = deleteinbst(root -> right, data);
        return root;
    }
}

int main(){
    Node* root = Build();
    int s;
    cin >> s;
    inorder(root);
    cout << "\n";
    root = deleteinbst(root, s);
    inorder(root);
    cout << "\n";
    bfs(root);
    return 0;
}