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

void push(struct node** head,int data)
{
	struct node* newnode=getnewnode(data);
	newnode->next=(*head);
	*head=newnode;
}

void pop(struct node** head)
{
	struct node* temp=*head;
	*head=temp->next;
	free(temp);
}

int isempty(struct node* head)
{
	return (head==NULL);
}

void printstack(struct node* head)
{
	while(head!=NULL)
	{
		cout<<head->data<<" ";
		head=head->next;
	}
	cout<<endl;
}

void insert_atbottom(struct node** head,int item)
{
	if(isempty(*head))
	push(head,item);
	else
	{
		int temp=(*head)->data;
		pop(head);
		insert_atbottom(head,item);
		
		push(head,item);
	}
}

void reverse(struct node** head)
{
	if(!isempty(*head))
	{
		int temp=(*head)->data;
		pop(head);
		reverse(head);
		
		insert_atbottom(head,temp);
	}
}

int main()
{
	stack<int> S;
	for(int i=0;i<5;i++)
	{
		S.push(i);
	}
}
