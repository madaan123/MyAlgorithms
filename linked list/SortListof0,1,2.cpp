#include<bits/stdc++.h>
using namespace std;

struct node{
	int data;
	node* next;
};

node* getnode(int data)
{
	node* newnode=new node;
	newnode->next=NULL;
	newnode->data=data;
	return newnode;
}

void append(node** head,int x)
{
	node* newnode=getnode(x);
	node* temp=*head;
	
	if((*head)==NULL)
	{
		*head=newnode;
		return;
	}
	
	while(temp->next)
	{
		temp=temp->next;
	}
	
	temp->next=newnode;
}

void push(node** head,int x)
{
	node* newnode=getnode(x);
	newnode->next=*head;
	*head=newnode;
}

void pop(node** head)
{
	node* temp=*head;
	*head=temp->next;
	free(temp);
}

void printlist(node* head)
{
	while(head)
	{
		cout<<head->data<<" ";
		head=head->next;
	}
	cout<<endl;
}

void sortlist(node* head)					// general program to sort a linked list of 0,1,2 by using extra variables
{
	int count[3]={0};
	node* temp=head;
	while(temp)
	{
		count[temp->data]++;
		temp=temp->next;
	}
	
	temp=head;
	for(int i=0;i<count[0];i++)
	{
		temp->data=0;
		temp=temp->next;
	}
	for(int i=0;i<count[1];i++)
	{
		temp->data=1;
		temp=temp->next;
	}
	for(int i=0;i<count[2];i++)
	{
		temp->data=2;
		temp=temp->next;
	}
}

node* sortlist1(node* head)
{											// function to sort a linked list of 0,1,2 by creating individual lists of 0,1,2 and then merging them
	node* list[3];
	list[0]=NULL;
	list[1]=NULL;
	list[2]=NULL;
	
	node* temp=head;
	while(temp)
	{
		push(&list[temp->data],temp->data);
		temp=temp->next;
	}
	
	head=NULL;
	int index=0;
	temp=list[0];
	while(index<3)
	{
		if(list[index]==NULL)
		{
			index++;
			continue;
		}
		
		if(head==NULL)
		head=list[index];
		else
		temp->next=list[index];
		
		temp=list[index];
		while(temp->next)
		temp=temp->next;
		
		index++;
	}
	temp->next=NULL;
	return head;
}

int main()
{
	node* head=NULL;
	int n;
	cin>>n;
	int x;
	for(int i=0;i<n;i++)
	{
		cin>>x;
		append(&head,x);
	}
	printlist(head);
	head=sortlist1(head);
	printlist(head);
}
