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

int main(){
    node *head = NULL;
    insertathead(head, 5);
    insertathead(head, 4);
    insertathead(head, 7);
    insertattail(head, 9);
    insertinmiddle(head, 2, 3);  
    
    /*
    deleteathead(head);
    deleteattail(head);
    deletefrommid(head, 3);
    */
    
    reverselist(head);
    print(head);
    
    /*
    if (searchelerecursive(head, 4)){
        cout << "Present" << "\n";
    }
    else{
        cout << "Not Present" << "\n";
    }
    if (searcheleiterative(head, 14)){
        cout << "Present" << "\n";
    }
    else
    {
        cout << "Not Present" << "\n";
    }
    */
    head = reverserec(head);
    print(head);

    return 0;
}