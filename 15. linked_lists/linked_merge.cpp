//merge two sorted linked list

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

void deleteathead(node* &head){
    if (head == NULL){
        return;
    }
    node* temp = head;
    head = head -> next;
    delete temp;
    return;
}

void deleteattail(node* &head){
    node *prev = NULL;
    node *temp = head;
    while (temp -> next != NULL){
        prev = temp;
        temp = temp -> next;
    }
    delete temp;
    prev -> next = NULL;
    return;
}

void deletefrommid(node* &head, int p){
    if (head == NULL){
        return ;
    } 
    if (head -> next == NULL){
        delete head;
        return;
    }

    node *slow_ptr = head;
    node *fast_ptr = head;

    node *prev;
    while   (fast_ptr != NULL && fast_ptr ->next != NULL){
        fast_ptr = fast_ptr -> next -> next;
        prev = slow_ptr ;
        slow_ptr = slow_ptr -> next;
    }

    //delte middle node
    prev -> next = slow_ptr ->next;
    delete slow_ptr;
    return;
}

bool searchelerecursive(node* head, int key){
    if (head == NULL){
        return false;
    }
    if (head -> data == key){
        return true;
    }
    else{
        return searchelerecursive(head -> next, key);
    }
}

bool searcheleiterative(node* head, int key){
    while(head != NULL){
        if (head -> data == key){
            return true;
        }
        head = head -> next;
    }
    return false;
}

//iterative method
void reverselist(node* &head){
    node* C = head;
    node* P = NULL;
    node* N;
    while (C != NULL){
        N = C-> next;
        C -> next = P;
        P = C;
        C = N;
    }
    head = P;
}

//recursive method
node* reverserec(node* head){
    if (head -> next == NULL || head == NULL){
        return head;
    }
    node* small_Head = reverserec(head -> next);
    node* C = head;
    C -> next -> next = C;
    C -> next = NULL;
    return small_Head;
}

node* midpoint(node* head){
    if (head == NULL || head -> next == NULL){
        return head;
    }
    node* slow = head;
    node* fast = head -> next;

    while(fast != NULL && fast -> next != NULL){
        fast = fast -> next -> next;
        slow = slow -> next;
    }
    return slow; 
}

void printnfromlast(node* head, int k){
    int len=0, i;
    node* temp = head;
    while(temp != NULL){
        temp = temp -> next;
        len++;
    }

    if (len < k){
        return;
    }
    temp = head;

    for (i=1; i<len - k+1; i++){
        temp = temp -> next;
    }
    cout << temp -> data;
    return;
}

node* merge(node* a, node*b){
    if (a==NULL){
        return b;
    }
    else if(b==NULL){
        return a;
    }
    node* c;

    if ( a->data < b->data ){
        c =a;
        c->next=merge(a-> next, b);
    }
    else{
        c = b;
        c -> next = merge(a, b-> next);
    }
    return c;
}

void insertAtTail(node*&head,int data){
    
    if(head==NULL){
        head = new node(data);
        return;
    }
    node*tail = head;
    while(tail->next!=NULL){
        tail = tail->next;
    }
    tail->next = new node(data);
    return;
}

void buildList(node*&head){
    
    int data;
    cin>>data;
    
    while(data!=-1){
        insertAtTail(head,data);
        cin>>data;
    }
}


istream& operator>>(istream &is,node*&head){
    buildList(head);
    return is;
}

ostream& operator<<(ostream &os,node*head){
    print(head);
    return os;
}

int main(){
    node* head = NULL;
    node* head2 = NULL;  
    cin >> head >> head2;
    head = (head);
    cout << head << "\n" << head2;
    head = merge(head, head2);
    cout << head;

    return 0;
}