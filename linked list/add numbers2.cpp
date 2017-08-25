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
	node* newnode=getnewnode(data);
	newnode->next=*head;
	*head=newnode;
}

int length(node* head)
{
	int c=0;
	while(head!=NULL)
	{
		c++;
		head=head->next;
	}
	return c;
}

int AddnumAux1(node* num1,node* num2,node** res)
{
	if(num1==NULL)
	{
		return 0;
	}
	
	int k=AddnumAux1(num1->next,num2->next,res);
	
	int s=num1->data+num2->data+k;
	push(res,s%10);
	return s/10;
}

void AddnumAux2(node* num1,int l,node** res,int *carry)
{
	if(l==0)
	{
		return;
	}
	AddnumAux2(num1->next,l-1,res,carry);
	
	int s=*carry+num1->data;
	push(res,s%10);
	*carry=s/10;
}

struct node* addnum(struct node** num1,struct node** num2)
{
	node* res=NULL;
	int carry=0,k;
	int l1=length(*num1);
	int l2=length(*num2);
	int l=abs(l1-l2);
	if(l1>=l2)
	{
		node* temp=*num1;
		while(l--)
		temp=temp->next;
		k=AddnumAux1(temp,*num2,&res);
		AddnumAux2(*num1,l1-l2,&res,&k);
	}
	else
	{
		node* temp=*num2;
		while(l--)
		temp=temp->next;
		int k=AddnumAux1(temp,*num1,&res);
		AddnumAux2(*num2,l2-l1,&res,&k);
	}
	if(k)
	{
		push(&res,k);
	}
	return res;
}

int main()
{
	struct node* num1=NULL;
	struct node* num2=NULL;
	int n1,n2;
	cin>>n1>>n2;
	while(n1)
	{
		push(&num1,n1%10);
		n1=n1/10;
	}
	while(n2)
	{
		push(&num2,n2%10);
		n2=n2/10;
	}
	struct node* result=addnum(&num1,&num2);
	printlist(result);
}
