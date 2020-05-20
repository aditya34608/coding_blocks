#include <iostream>

using namespace std;

class node{
public:
    int data;
    node *next;

    node(int d){
        data = d;
        next = NULL;
    }
};

//pass by reference
void insertathead(node* &head, int data){
    node* n = new node(data);
    n-> next = head;
    head = n;
}

int length(node* head){
    int len=0;
    while (head != NULL){
        head = head -> next;
        len += 1;
    }
    return len;
}

void insertattail(node* &head, int data){
    if (head == NULL){
        head = new node(data);
        return;
    }
    node* tail = head;
    while (tail -> next != NULL){
        tail = tail -> next;
    }
    tail -> next = new node(data);
    return;
    
}

void insertinmiddle(node* &head, int data, int p){
    if (head == NULL || p == 0){
        insertathead(head, data);
    }
    else if(p > length(head)){
        insertattail(head, data);
    }
    else{
        // insert in middle
        int jump = 1;
        node *temp = head;
        while (jump <= p-1){
            temp = temp -> next;
            jump += 1;
        }
        node *n = new node(data);
        n -> next = temp -> next;
        temp -> next = n;
    }
}

void print(node* head){
    node *temp = head;

    while (temp != NULL){
        cout << temp -> data << "->";
        temp = temp -> next;
    }
    cout << "\n";
}

int main(){
    node *head = NULL;
    insertathead(head, 5);
    insertathead(head, 4);
    insertathead(head, 7);
    insertattail(head, 9);
    insertinmiddle(head, 2, 3);
    print(head);

    return 0;
}