#include<bits/stdc++.h>
using namespace std;

struct node{
	int data;
	struct node* next;
};

void printlist(struct node* head)
{
	while(head!=NULL)
	{
		cout<<head->data<<" ";
		head=head->next;
	}
	cout<<endl;
}

void push(struct node** head,int data)
{
	struct node* newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=data;
	newnode->next=(*head);
	(*head)=newnode;
}

void append(struct node** head,int data)
{
	struct node* temp=*head;
	struct node* newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=data;
	newnode->next=NULL;
	if((*head)==NULL)
	{
		*head=newnode;
		return;
	}
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	temp->next=newnode;
}

void skipMdeleteN(struct node** head,int M,int N)
{
	struct node *curr=*head,*temp;
	while(curr)
	{
		for(int i=1;i<M && curr!=NULL;i++)
		{
			curr=curr->next;
		}
		if(curr==NULL)
		return;
		
		temp=curr->next;
		for(int i=1;i<=N && temp!=NULL;i++)
		{
			struct node* temp2=temp;
			temp=temp->next;
			free(temp2);
		}
		
		curr->next=temp;
		curr=temp;
	}
}

bool isCircular(struct node* head)
{
	if(head==NULL)
	return true;
	struct node* temp=head->next;
	while(temp!=NULL && temp->next!=head)
	temp=temp->next;
	
	return (temp==head);
}

void deletepos(struct node** head,int pos)
{
	if(head==NULL)
	return;
	
	struct node* temp=*head;
	
	if(pos==0)
	{
		*head=temp->next;
		free(temp);
		return;
	}
	
	for(int i=1;i<pos && temp!=NULL;i++)
	temp=temp->next;
	
	if(temp==NULL || temp->next==NULL)
	return;
	
	struct node* nextnode=temp->next->next;
	
	free(temp->next);
	
	temp->next=nextnode;
}

int detectloop(struct node* head)
{
	struct node *slow,*fast;
	slow=fast=head;
	while(slow && fast && fast->next)
	{
		slow=slow->next;
		fast=fast->next->next;
		if(slow==fast)
		return 1;
	}
	return 0;
}

int getNth(struct node* head,int n)
{
	struct node* temp=head;
	int index=0;
	while(temp!=NULL)
	{
		if(index==n)
		return temp->data;
		index++;
		temp=temp->next;
	}
	return -1;
}

void deletelist(struct node** head)
{
	struct node* temp=*head;
	struct node* next;
	while(temp!=NULL)
	{
		next=temp->next;
		free(temp);
		temp=next;
	}
	*head=NULL;
}

void printreverse(struct node* head)
{
	if(head==NULL)
	return;
	
	printreverse(head->next);
	
	cout<<head->data<<" ";
}

int decimal_equivalent(struct node* head)
{
	int result=0;
	while(head!=NULL)
	{
		result=(2*result)+head->data;
		head=head->next;
	}
	return result;
}

int main()
{
	struct node* head=NULL;
	append(&head,5);
	append(&head,5);
	append(&head,5);
	append(&head,5);
	//skipMdeleteN(&head,1,1);
	printlist(head);
	cout<<getNth(head,4);
}
