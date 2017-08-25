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

void reverseprint(struct node* head)
{
	if(head==NULL)
	return;
	
	reverseprint(head->next);
	
	cout<<head->data;
}

struct node* addnum1(struct node* num1,struct node* num2)
{
	struct node* result=NULL;
	struct node* last=NULL;
	int carry=0;
	int n;
	while(num1 || num2)
	{
		n=carry;
		if(num1)
		{
			n+=num1->data;
			num1=num1->next;
		}
		if(num2)
		{
			n+=num2->data;
			num2=num2->next;
		}
		struct node* newnode=getnewnode(n%10);
		if(result==NULL)
		result=newnode;
		else
		last->next=newnode;
		
		last=newnode;
		carry=n/10;
	}
	if(carry)
	last->next=getnewnode(carry);
	
	return result;
}

int main()
{
	struct node* num1=NULL;
	struct node* num2=NULL;
	int n1,n2;
	cin>>n1>>n2;
	while(n1)
	{
		append(&num1,n1%10);
		n1=n1/10;
	}
	while(n2)
	{
		append(&num2,n2%10);
		n2=n2/10;
	}
	struct node* result=addnum1(num1,num2);
	reverseprint(result);
}
