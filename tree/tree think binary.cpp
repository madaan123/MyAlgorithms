#include<bits/stdc++.h>
using namespace std;

struct node{
	int data;
	struct node *left,*right;
	struct node* nextRight;
};

struct node* newnode(int data)							// creation of a nenode iof a tree
{
	struct node* newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=data;
	newnode->left=NULL;
	newnode->right=NULL;
	return newnode;
}

struct node* insert(struct node* root,int data)				// insertion in a binary search tree
{
	if(root==NULL)
	{
		root=newnode(data);
	}
	else if(data<root->data)
	{
		root->left=insert(root->left,data);
	}
	else
	{
		root->right=insert(root->right,data);
	}
	return root;
}

int diameter(struct node* root,int *height)
{
	int ld=0,rd=0,lh=0,rh=0;
	
	if(root==NULL)
	{
		*height=0;
		return 0;
	}
	
	ld=diameter(root->left,&lh);
	rd=diameter(root->right,&rh);
	
	*height=max(lh,rh)+1;
	
	return max(max(ld,rd),(lh+rh+1));
}

void swapKthlevel(node* root,int k,int level=1)				// function to swap the nodes at kth level wgere k>=1
{
	if(root==NULL)
	return;
	
	if((level+1)%k==0)								// any level that is a multiple of k will have its nodes swapped
	{
		node* temp=root->right;
		root->right=root->left;
		root->left=temp;
	}
	
	swapKthlevel(root->left,k,level+1);
	swapKthlevel(root->right,k,level+1);
}

void levelorder(struct node* root)
{
	if(root==NULL)
	return;
	
	queue<struct node*>Q;
	Q.push(root);
	while(!Q.empty())
	{
		int c=Q.size();
		while(c--)
		{
			node* curr=Q.front();
			Q.pop();
			cout<<curr->data<<" ";
			if(curr->left)
			Q.push(curr->left);
			if(curr->right)
			Q.push(curr->right);
		}
		cout<<endl;
	}
}

void levelorder2(node* root)
{
	if(root==NULL)
	return;
	
	queue<struct node*>Q;
	Q.push(root);
	Q.push(NULL);
	while(!Q.empty())
	{
		node* curr=Q.front();
		Q.pop();
		if(curr)
		{
			cout<<curr->data<<" ";
			if(curr->left)
			Q.push(curr->left);
			if(curr->right)
			Q.push(curr->right);
		}
		else
		{
			cout<<endl;
			if(!Q.empty())
			Q.push(NULL);
		}
	}
}

void levelorder_spiral(struct node* root)
{												// function to output levelorder in spiral order
	if(root==NULL)
	return;										// alternate traversal first level left from right and then alternatively right to left
	
	stack<struct node*>S1,S2;
	S1.push(root);
	while(!S1.empty() || S2.empty())
	{
		while(!S1.empty())
		{
			node* curr=S1.top();
			S1.pop();
			cout<<curr->data<<" ";
			if(curr->left)
			S2.push(curr->left);
			if(curr->right)
			S2.push(root->right);
		}
		cout<<endl;
		while(!S2.empty())
		{
			node* curr=S2.top();
			S2.pop();
			cout<<curr->data<<" ";
			if(curr->right)
			S1.push(root->right);
			if(curr->left)
			S1.push(curr->left);
		}
		cout<<endl;
	}
}

void leftviewAux(struct node* root,int level,int * maxlevel)
{
	if(root==NULL)
	return;
													// function to print left view of a tree
	if(level>*maxlevel)
	{
		cout<<root->data<<" ";
		*maxlevel=level;
	}
	
	leftviewAux(root->left,level+1,maxlevel);
	leftviewAux(root->right,level+1,maxlevel);
}

void leftview(struct node* root)
{
	int maxlevel=0;
	leftviewAux(root,1,&maxlevel);
}

void rightviewAux(struct node* root,int level,int * maxlevel)
{
	if(root==NULL)
	return;
	
	if(level>*maxlevel)
	{
		cout<<root->data<<" ";
		*maxlevel=level;
	}
	
	rightviewAux(root->right,level+1,maxlevel);
	rightviewAux(root->left,level+1,maxlevel);
}

void rightview(struct node* root)
{
	int maxlevel=0;
	rightviewAux(root,1,&maxlevel);
}

void verticalSumsAux(node* root,map<int,int>&levelsums,int level=0)
{
	if(root==NULL)
	return;
	
	levelsums[level]+=root->data;
	
	verticalSumsAux(root->left,levelsums,level-1);
	verticalSumsAux(root->right,levelsums,level+1);
}

void verticalSums(node* root)							// program to print vertical sum in  a binary tree
{
	map<int,int>levelsums;
	verticalSumsAux(root,levelsums);
	map<int,int>::iterator it;
	for(it=levelsums.begin();it!=levelsums.end();it++)
	{
		cout<<"level "<<it->first<<" Sum: "<<it->second<<endl;
	}
}

typedef map<int,pair<int,int> >mymap;

void topViewAux(node* root,mymap& m,int level=1,int hd=0)
{																// auxillary function to print top view of a binary tree
	if(!root)
	return;														// important
	
	if(m.find(hd)==m.end() || (level<m[hd].first))
	{
		m[hd]=make_pair(level,root->data);
	}
	topViewAux(root->left,m,level+1,hd-1);
	topViewAux(root->right,m,level+1,hd+1);
}

void topView(node* root)
{
	mymap m1;
	topViewAux(root,m1);
}

void DiagonalView(node* root,map<int,vector<int> > &D1,int hd)
{
	if(root==NULL)
	return;
	
	D1[hd].push_back(root->data);
	
	DiagonalView(root->left,D1,hd-1);
	DiagonalView(root->right,D1,hd);
}

void DiagonalTreeTraversal(node* root)
{
	map<int,vector<int> > D1;
	DiagonalView(root,D1,0);
	
	map<int,vector<int> >::iterator it;
	
	for(it=D1.begin();it!=D1.end();it++)
	{
		for(int itr=0;itr<it->second.size();itr++)
		cout<<it->second[itr]<<" ";
		
		cout<<endl;
	}
}

void DiagonalSum(node* root,map<int,int> &DSum,int hd)
{
	if(root==NULL)
	return;
	
	DSum[hd]+=root->data;
	
	DiagonalSum(root->left,DSum,hd+1);
	DiagonalSum(root->right,DSum,hd);
}

void TreeDiagonalSum(node* root)
{
	map<int,int> D1;
	DiagonalSum(root,D1,0);
	
	map<int,int>::iterator it;
	
	for(it=D1.begin();it!=D1.end();it++)
	{
		cout<<it->second<<" ";
	}
}

node* constructTreeFromInPost(int *in,int *post,int n)
{
	if(n==0)
	return NULL;
	
	node* root=newnode(post[n-1]);
	int i;
	for(i=0;i<n;i++)
	{
		if(in[i]==post[n-1])
		break;
	}
	
	root->left=constructTreeFromInPost(in+1,post+i,i);
	root->right=constructTreeFromInPost(in+i+1,post+i,n-i-1);
	
	return root;
}

node* getnextright(node* root)
{
	root=root->nextRight;
	while(root!=NULL)
	{
		if(root->left!=NULL)
		return root->left;
		if(root->right!=NULL)
		return root->right;
		root=root->nextRight;
	}
	return NULL;
}

void connectRight(node* root)										// function to connect the nodes at same level
{
														//		 A					A->NULL
														//		/ \				   / \
														//	   B  C				  B ->C->NULL
														//	  / \  \			 / \  \
														//	 D   E  F			D ->E->F->NULL															  D ->E->F->NULL
	root->nextRight=NULL;
	node* firstAtLevel=root;
	while(firstAtLevel)
	{
		node* iter=firstAtLevel;
		while(iter)
		{
			if(iter->left)
			{
				if(iter->right)
				{
					iter->left->nextRight=iter->right;
					iter->right->nextRight=getnextright(iter);
				}
				else
				iter->left->nextRight=getnextright(iter);
			}
			else if(iter->right)
			{
				iter->right->nextRight=getnextright(iter);
			}
			iter=iter->nextRight;
		}
		
		if(firstAtLevel->left)
		firstAtLevel=firstAtLevel->left;
		else if(firstAtLevel->right)
		firstAtLevel=firstAtLevel->right;
		else
		firstAtLevel=getnextright(firstAtLevel);
	}
}

int main()
{
	struct node* root=NULL;					//creation of a bst
	int n,x;
	cout<<"enter number of elements in a tree"<<endl;
	cin>>n;
	cout<<"enter elements"<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>x;
		root=insert(root,x);			// insertion of a bst
	}
	int h=0;
    //cout<<diameter(root,&h);
    levelorder(root);
    swapKthlevel(root,1,1);
    levelorder2(root);
    rightview(root);
    cout<<endl;
    verticalSums(root);
    connectRight(root);
}
