#include <iostream>

using namespace std;

class node{
public:
    int data;
    node* next;

    //Constructor 
    node(int d){
        data = d;
        next = NULL;
    }
};

void insertAtTail(node*&head,int data){
    if(head == NULL){
        head = new node(data);
        return;
    }
    node *tail = head;
    while(tail->next != NULL){
        tail = tail->next;
    }
    tail->next = new node(data);
}

int buildList(node*&head){
    int n;
    cin>>n;
    int a=n;
    while(n--){
        int data;
        cin>>data;
        insertAtTail(head,data);
    }
    return a;
}

void printList(node*head){
    if(head == NULL){
        return;
    }
    cout<<head->data<<" ";
    printList(head->next);
}

node* checkList(node*head,int k,int n){
    node*last;
    last = head;
    int i=0;
    k = k%n;
    int ok = n-k-1; 
    while(last != NULL && i<ok){
        last = last -> next;
       i++;
    }
    node*second = last->next;
    last->next = NULL;
    return second;
}

int main() {
    int k;
    node* head = NULL;
    int n = buildList(head);
    cin>>k;
    node* temp = checkList(head,k,n);
    printList(temp);
    printList(head);
}