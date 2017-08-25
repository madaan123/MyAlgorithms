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

void append(struct node** head,int data)						// add a node at the end of the linked list
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

void printlist(struct node* head)				// print all the nodes of the linked list
{
	while(head!=NULL)
	{
		cout<<head->data<<" ";
		head=head->next;
	}
	cout<<endl;
}

void reverseprint(struct node* root)				// print linked list in reverse order
{
	if(root==NULL)
	return;
	reverseprint(root->next);
	cout<<root->data<<" ";
}

void push(struct node** head,int key)									// push a node at the the top of the linked list
{
	struct node* newnode=(struct node*)malloc(sizeof(struct node));
	newnode->next=(*head);
	*head=newnode;
}
		
void pop(struct node** head)									// remove a node from top of the linked list
{
	node* temp=*head;
	*head=temp->next;
	free(temp);
}

void rotatelistleft(struct node** head,int k)				//rotate the list left by k positions
{
	if(*head==NULL || k==0)
	return;
	struct node *iter=*head;
	struct node* end;
	while(iter->next!=NULL)
	{
		if(--k==0)
		end=iter;
		iter=iter->next;
	}
	iter->next=*head;
	*head=end->next;
	end->next=NULL;
}

struct node* rotatelistright(struct node* head,int k)				//rotate the list right by k positions
{
	if(head==NULL)												// the value of k can be greater than the length of the linked list
	return NULL;
	
	struct node *slow=head,*fast=head;
	int length=0;
	while(k--)
	{
		fast=fast->next;
		length++;
		if(fast==NULL)
		{
			k=k%length;
			fast=head;
		}
	}
	if(fast==head)
	return head;
	
	while(fast->next!=NULL)
	{
		fast=fast->next;
		slow=slow->next;
	}
	
	fast->next=head;
	head=slow->next;
	slow->next=NULL;
	
	return head;
}

node* SortedMerge(node* head1,node* head2)					// function to merge two sorted linked list
{
    // Your Code Here
    struct node* result=NULL;
    if(head1==NULL)
    return head2;
    if(head2==NULL)
    return head1;
    
    if(head1->data<=head2->data)
    {
        result=head1;
        result->next=SortedMerge(head1->next,head2);
    }
    
    else
    {
        result=head2;
        result->next=SortedMerge(head1,head2->next);
    }
    
    return result;
}

struct node* kthnode_fromend(struct node* head,int k)			// program to print kth node from end
{
	if(head==NULL)
	return NULL;
	node* temp=head;
	while(temp!=NULL && k--)
	temp=temp->next;
	
	while(temp!=NULL)
	{
		temp=temp->next;
		head=head->next;
	}
	
	return head;
}

void swap(struct node** head,int x,int y)					// swap two nodes without swapping data
{
	if(x==y)
	return;
	node *prevX=NULL,*prevY=NULL,*curX=*head,*curY=*head;
	while(curX && curX->data!=x)
	{
		prevX=curX;
		curX=curX->next;
	}
	
	while(curY && curY->data!=y)
	{
		prevY=curY;
		curY=curY->next;
	}
	
	if(curX==NULL || curY==NULL)				// if any two nodes is not present in the data
	return;
	
	if(prevX!=NULL)
	prevX->next=curY;
	else
	*head=curY;
	
	if(prevY!=NULL)
	prevY->next=curX;
	else
	*head=curX;
	
	node* temp=curY->next;
	curY->next=curX->next;
	curX->next=temp;
}

struct node* deletelist(node* head)
{
	node* temp=head;
	node* next;
	while(temp)
	{
		next=temp->next;
		free(temp);
		temp=next;
	}
	return NULL;
}

void reverse(struct node** head)					// function to reverse a linked list 
{
	node* prev=NULL;
	node* curr=*head;
	node* next;
	
	while(curr)
	{
		next=curr->next;
		curr->next=prev;
		prev=curr;
		curr=next;
	}
	*head=curr;
}

	int length(node* head)					// function to find the length of a lined list
   {
       int l=0;
       while(head!=NULL)
       {
           l++;
           head=head->next;
       }
       return l;
   }

int intersectPoint(node* head1, node* head2)			// function to find the intersection of two y shaped linked lists
{
    int l1,l2;
    l1=length(head1);
    l2=length(head2);
    
    node* temp1=(l1>l2)?head1:head2;
    node* temp2=(l1<l2)?head1:head2;
    int l=max(l1,l2)-min(l1,l2);
    while(l--)
    {
        temp1=temp1->next;
    }
    while(temp1 && temp2)
    {
        if(temp1==temp2)
        return temp1->data;
        temp1=temp1->next;
        temp2=temp2->next;
    }
    return -1;
}

void remove_duplicates(struct node* head)				// function to remove duplicated=s from the sorted linked lists
{
	node* nextnext;
	node* curr=head;
	
	if(head==NULL)
	return;
	
	while(curr->next!=NULL)
	{
		if(curr->data=curr->next->data)
		{
			nextnext=curr->next->next;
			free(curr->next);
			curr=nextnext;
		}
		else
		curr=curr->next;
	}
}

node *removeDuplicates(node *root)					// function to remove duplicates from a unsorted list
{
 // your code goes here
 node* curr=root;
 node* temp;
 
 while(curr && curr->next)
 {
     temp=curr;
     while(temp->next!=NULL)
     {
         if(temp->next->data==curr->data)
         {
             node* temp2=temp->next;
             temp->next=temp->next->next;
             free(temp2);
         }
         else
         temp=temp->next;
     }
     curr=curr->next;
 }
 return root;
}

void intersection(node **head1, node **head2,node **head3)				// function to find intersection of two sorted lists
{
    // Your Code Here
    node* a=*head1;
    node* b=*head2;
    node* temp;
    while(a && b)
    {
        if(a->data==b->data)
        {
            if(*head3==NULL)
            {
                *head3=a;
            }
            else
            temp->next=a;
            
            temp=a;
            b=b->next;
            a=a->next;
        }
        
        else if(a->data<b->data)
        a=a->next;
        else
        b=b->next;
    }
}

bool identical(node* head1,node* head2)					// function to check if two lists are identical or not
{
	while(head1 && head2)
	{
		if(head1->data!=head2->data)
		return false;
		
		head1=head1->next;
		head2=head2->next;
	}
	return (head1==NULL && head2==NULL);
}

void deletealt(struct node* head)					// delete alternate nodes of a linked list
{
	if(head==NULL)								// 1->2->3->4->5 then your function should convert it to 1->3->5
	return;
	node* curr=head;
	node* node=head->next;
	while(curr!=NULL && node!=NULL)
	{
		curr->next=node->next;
		free(node);
		curr=curr->next;
		if(curr!=NULL)
		node=curr->next;
	}
}

void deleteAltRecur(node* head)					// recursive function to delete alternate nodes in a linked list
{
	if(head==NULL)
	return;
	
	node* node=head->next;
	if(node==NULL)
	return;
	
	head->next=node->next;
	free(node);
	deleteAltRecur(head->next);
}

struct node *reverse (struct node *head, int k)				// function to reverse a list in sizs of k sections
{
    struct node* current = head;
    struct node* next = NULL;
    struct node* prev = NULL;
    int count = 0;   
     
    /*reverse first k nodes of the linked list */
    while (current != NULL && count < k)
    {
        next  = current->next;
        current->next = prev;
        prev = current;
        current = next;
        count++;
    }
     
    /* next is now a pointer to (k+1)th node 
       Recursively call for the list starting from current.
       And make rest of the list as next of first node */
    if (next !=  NULL)
       head->next = reverse(next, k); 
 
    /* prev is new head of the input list */
    return prev;
}

void skipMdeleteN(node* head,int m,int n)
{
	node* curr=head;
	node* t;
	while(curr)
	{
		for(int i=1;i<m && curr!=NULL;i++)
		curr=curr->next;
		
		if(curr==NULL)
		return;
		
		node* t=curr->next;
		for(int i=0;i<n && t!=NULL;i++)
		{
			node* temp=t;
			t=t->next;
			free(temp);
		}
		
		curr->next=t;
		curr=t;
	}
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
	printlist(head);
}
