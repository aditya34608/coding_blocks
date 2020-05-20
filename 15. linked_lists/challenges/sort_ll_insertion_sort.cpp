/*
Given a linked list with n nodes. Sort the linked list using insertion sort.
Input Format

First line contains the number of nodes in the linked list n and then next line contains n space separated integers representing the node values of the linked list.
Constraints

n < 30
Output Format

Print the linked list after sorting it using insertion sort.
Sample Input

5
2 3 4 1 5

Sample Output

1 2 3 4 5

Explanation

None

*/

#include<iostream>
using namespace std;

class node{
public:
    int data;
    node *next;
    node(int d){
        data=d;
        next=NULL;
    }
};

void insertAtTail(node *&head,int data){
    if(head == NULL){
        head = new node(data);
        return;
    }
    node *t = head;
    while(t -> next != NULL){
        t = t -> next;
    }
    t -> next = new node(data);
    return;
}

void buildlist(node *&head){
    int N, data;
    cin >> N;
    while(N>0){
        cin >> data;
        insertAtTail(head,data);
        N--;
    }
}

void segregate(node *&head){
    node *current_ptr = head;
    node *insert_ptr = head;
    current_ptr = head -> next;
    while(current_ptr != NULL){
        insert_ptr = head;
        while(insert_ptr != current_ptr){
            if(insert_ptr -> data >= current_ptr -> data){
                int temp = current_ptr -> data;
                current_ptr -> data = insert_ptr -> data;
                insert_ptr -> data = temp;
            }
            else{
                insert_ptr = insert_ptr -> next;
            }
        }
        current_ptr = current_ptr->next;
    }
}

void print(node *head)
{
    while(head != NULL){
        cout << head -> data << " ";
        head = head -> next;
    }
}

int main() {
    node *head = NULL;
    buildlist(head);
    segregate(head);
    print(head);
	return 0;
}

