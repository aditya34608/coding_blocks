/*


There are two linked lists. Due to some programming error, the end node of one of the linked list got linked into the second list, forming an inverted Y shaped list. Now it's your job to find the point(Node) at which the two linked lists are intersecting.
Input Format

The first line of input is the size(N1) of the first linked list, followed by its content(Xi). The third line of input is the size(N2) of the second linked list, followed by its content( Yi ).
Constraints

1<=N, N2<=100 0<=Xi, Yi<=100
Output Format

A single integer denoting the intersection point of two linked lists. If the linked lists are not intersecting at any point then print -1.
Sample Input 

5
10 20 30 40 50
4
15 25 40 50

Sample Output

40

Explanation

First and second linked list intersect at the node whose data value is 40.

*/

#include<iostream>
#include<cmath>

using namespace std;

class node{
public:
    int data;
    node*next;
    node(int d){
        data=d;
        next=NULL;
    }
};

void ins(node*&head,int d){
    if(head==NULL){
        head=new node(d);
        return;
    }
    node*temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=new node(d);
    return;
}
void print(node*head){
    if(head==NULL){
        return;
    }
    while(head->next!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<head->data<<endl;
    return;
}
int dataaa(node*head,node*head2,int d)
{
    node*temp=head;
    node*temp2=head2;
    while(d--)
    {
        temp=temp->next;
    }
    while(temp!=NULL && temp2!=NULL)
    {
        if(temp->data==temp2->data)
        {
            return temp->data;
        }
        temp=temp->next;
        temp2=temp2->next;
    }
    return -1;
}

int main() 
{
    int n,m;
    node*head=NULL;
    node*head2=NULL;
    cin>>n;
    int n1=n;

    while(n--)
    {
        int d;
        cin>>d;
        ins(head,d);
    }
    cin>>m;
    int m1=m;
    int d=abs(n1-m1);
    while(m--)
    {
        int d;
        cin>>d;
        ins(head2,d);
    }
    //print(head);
    //print(head2);
    if(n1>=m1)
    {
        cout<<dataaa(head,head2,d);
    }
    else
    {
        cout<<dataaa(head2,head,d);
    }
	return 0;
}