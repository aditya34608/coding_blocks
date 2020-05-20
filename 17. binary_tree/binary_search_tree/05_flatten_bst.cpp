//convert a bst to sorted linked list

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

class ptr_pair{
    public:
        Node* head;
        Node* tail;
};

ptr_pair flatten(Node* root){
    ptr_pair p;
    if (root == NULL){
        p.head = p.tail = NULL;
        return p;
    }

    //leaf node
    if (root -> left == NULL && root -> right == NULL){
        p.head = p.tail = root;
        return p;
    }

    //left is not null
    if (root -> left != NULL && root -> right == NULL){
        ptr_pair leftLL = flatten(root -> left);
        leftLL.tail -> right = root;
        p.head = leftLL.head;
        p.tail = root;
        return p;
    }

    //right is not null
    if (root -> left == NULL && root -> right != NULL){
        ptr_pair rightLL = flatten(root -> right);
        root -> right = rightLL.head;

        p.head = root;
        p.tail = rightLL.tail;
        return p;
    }

    //both sides are not null
    ptr_pair leftLL = flatten(root -> left);
    ptr_pair rightLL = flatten(root -> right);
    leftLL.tail -> right = root;
    root -> right = rightLL.head;

    p.head = leftLL.head;
    p.tail = rightLL.head;

    return p;
}

int main(){
    Node* root = Build();
    ptr_pair p = flatten(root);
    Node* temp = p.head;
    while (temp != NULL){
        cout << temp -> data << "-->";
        temp = temp -> right;
    }
    cout << "\n";
    return 0;
}