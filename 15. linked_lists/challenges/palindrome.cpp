/*
Check if a linked list is a palindrome.( Boolean return type )
Input Format

Add N space separated elements in the list
Constraints

None
Output Format

Boolean answer( true or false)
Sample Input

5
1 2 3 6 8

Sample Output

False
*/

#include<iostream>
using namespace std;
class node
{
	public:
		int data;
		node* next;
		node(int d)
		{
			data=d;
			next=NULL;
		}
};
void insert(node* &head,int data)
{
	if(head==NULL)
	{
		head=new node(data);
		return;
	}
	node* tail=head;
	while(tail->next!=NULL)
	{
		tail=tail->next;
	}
	tail->next=new node(data);
	return;
		
}
void list(node* &head,int n)
{
	int data;
	
	while(n--)
	{
		cin>>data;
		insert(head,data);
	}
}
int length(node* head)
{
	node* temp=head;
	int count=0;
	while(temp!=NULL)
	{
		temp=temp->next;
		count++;
	}
	return count;
}
void print(node* head)
{
	while(head!=NULL)
	{
		cout<<head->data<<" ";
		head=head->next;	
	}
}

node* Reverse(node* head)
{
	node* current=head;
	node* previous=NULL;
	node* N;
	
	while(current!=NULL)
	{
		N=current->next;
		current->next=previous;
		previous=current;
		current=N;
	}
	return previous;
}
bool palindrome(node* &head,node* &head2)
{
	while(head!=NULL && head2!=NULL)
	{
		if(head->data!=head2->data)
		{
			return false;
			break;
			
		}
		head=head->next;
		head2=head2->next;
		
	}
	return true;
}
int main()
{
	node* head=NULL;
	node* head2=NULL;
	int n;
	cin>>n;
	list(head,n);
	head2=Reverse(head);
	//print(head2);
	if(palindrome(head,head2)==true)
	{
		cout<<"true";
	}
	else
	{
		cout<<"false";
	}
}