#include<bits/stdc++.h>
using namespace std;

struct node{
	int data;
	struct node* next;
};

struct node* getnewnode(int data)
{
	struct node* newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=data;
	newnode->next=NULL;
	return newnode;
}

void append(struct node** head,int data)
{
	struct node* newnode=getnewnode(data);
	node* temp=*head;
	if((*head)==NULL)
	{
		*head=newnode;
		return;
	}
	
	while(temp->next!=NULL)
	temp=temp->next;
	
	temp->next=newnode;
}

void printlist(struct node* head)
{
	while(head!=NULL)
	{
		cout<<head->data<<" ";
		head=head->next;
	}
	cout<<endl;
}

struct node* detectloop(struct node* head)			// function to detect loop in a linked list
{
	struct node *slow=head,*fast=head;
	while(slow && fast && fast->next)
	{
		slow=slow->next;
		fast=fast->next->next;
		if(slow==fast)
		return fast;
	}
	return NULL;
}

void removeloop(struct node** head)					// function to remove the loop in the linked list
{
	struct node* loopnode=detectloop(*head);
	if(loopnode)
	{
		node* temp1=loopnode;
		node* temp2=loopnode;
		int l=0;
		while(temp2->next!=temp1)
		{											// traverse from the meeting point of slow and fast pointers till they meet
			l++;									// then remove the loop by setting the previous of the meeting point to null
			temp2=temp2->next;
		}
		temp1=*head;
		temp2=*head;
		for(int i=0;i<l;i++)
		temp2=temp2->next;
		
		while(temp1!=temp2)
		{
			temp1=temp1->next;
			temp2=temp2->next;
		}
		
		node* prev;
		while(temp2->next!=temp1)
		{
			prev=temp2;
			temp2=temp2->next;
		}
		prev->next=NULL;
	}
}

void generateloop(struct node** head)				// function to generate a loop in the linked list
{
	struct node* temp1=*head;
	struct node* temp2=*head;
	while(temp1->next!=NULL)
	temp1=temp1->next;
	
	for(int i=0;i<2;i++)
	temp2=temp2->next;
	
	temp1->next=temp2;
}

int main()
{
	struct node* head=NULL;
	int n;
	cin>>n;
	int x;
	for(int i=0;i<n;i++)
	{
		cin>>x;
		append(&head,x);
	}
	generateloop(&head);
	removeloop(&head);
	printlist(head);
}
