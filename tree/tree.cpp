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

struct node* search(struct node* root,int data)					// searching of a node in a binary search tree
{
	if(root==NULL)
	return NULL;
	
	else if(root->data==data)
	return root;
	
	else if(data<root->data)
	return search(root->left,data);
	
	else
	return search(root->right,data);
}

struct node* minimum(struct node* root)	;

struct node* delete_node(struct node* root,int key)					// function to delete a node from a binary search tree
{
	if(root==NULL)
	return NULL;
	
	if(key<root->data)
	root->left=delete_node(root->left,key);
	
	else if(key>root->data)
	root->right=delete_node(root->right,key);
	
	else
	{
		if(root->left==NULL && root->right==NULL)
		{
			free(root);
			root=NULL;
		}
		else if(root->left==NULL && root->right!=NULL)
		{
			struct node* temp=root;
			root=root->right;
			free(temp);
		}
		else if(root->left!=NULL && root->right==NULL)
		{
			struct node* temp=root;
			root=root->left;
			delete temp;
		}
		else
		{
			struct node* temp=minimum(root->right);
			root->data=temp->data;
			root->right=delete_node(root->right,temp->data);
		}
		return root;
	}
}

void preorder(struct node* root)					// recursive preorder traversal of a binary tree
{
	if(root==NULL)
	return;
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}

struct node* minimum(struct node* root)				// function to find minimum element in a binary search tree
{
	if(root==NULL)
	return root;
	
	while(root->left!=NULL)
	root=root->left;
	
	return root;
}

struct node* maximum(struct node* root)				// function to find minimum element in a binary search tree
{
	if(root==NULL)
	return root;
	
	while(root->right!=NULL)
	root=root->right;
	
	return root;
}

struct node* parent(struct node* root,int data)			// function to find parent node of a node
{	
	if(root==NULL || root->data==data)
	return NULL;
	
	if(root->left && root->left->data==data || root->right && root->right->data==data)
	return root;
	
	if(data<root->data)
	return parent(root->left,data);
	
	else if(data>root->data)
	return parent(root->right,data);
}

struct node* inorder_successor(struct node* root,int data)				// function to find inorder successor of a node if it exists
{
	struct node* current=search(root,data);
	if(current)
	{
		if(current->right!=NULL)
		{
			return minimum(root->right);
		}
		else
		{
			struct node* a=root;
			struct node* b=NULL;
			while(a!=current)
			{
				if(a->data>current->data)
				{
					b=a;
					a=a->left;
				}
				else
				a=a->right;
			}
			return b;
		}
	}
}

struct node* inorder_predecessor(struct node* root,int data)				// function to find predecessor successor of a node if it exists
{
	struct node* current=search(root,data);
	if(current)
	{
		if(current->left!=NULL)
		{
			return maximum(root->left);
		}
		else
		{
			struct node* a=root;
			struct node* b=NULL;
			while(a!=current)
			{
				if(a->data<current->data)
				{
					b=a;
					a=a->right;
				}
				else
				a=a->right;
			}
			return b;
		}
	}
}

int height(struct node* root)					// program to print height of a tree
{
	if(root==NULL)
	return 0;
	
	return max(height(root->left),height(root->right))+1;
}

int diameter(struct node* root,int *height)					//finding diameter of a tree
{
	int lh=0,rh=0;
	int ld=0,rd=0;
	if(root==NULL)
	{
		*height=0;
		return 0;
	}
	
	ld=diameter(root->left,&lh);
	rd=diameter(root->right,&rh);
	
	*height=max(lh,rh)+1;
	
	return max(lh+rh+1,max(ld,rd));
}

bool isBalanced(struct node *root, int* height)				// optimized code to check if a tree is height balanced or not
{
  /* lh --> Height of left subtree 
     rh --> Height of right subtree */   
  int lh = 0, rh = 0;  
 
  /* l will be true if left subtree is balanced 
    and r will be true if right subtree is balanced */
  int l = 0, r = 0;
     
  if(root == NULL)
  {
    *height = 0;
     return 1;
  }
 
  /* Get the heights of left and right subtrees in lh and rh 
    And store the returned values in l and r */   
  l = isBalanced(root->left, &lh);
  r = isBalanced(root->right,&rh);
 
  /* Height of current node is max of heights of left and 
     right subtrees plus 1*/   
  *height = (lh > rh? lh: rh) + 1;
     
  /* If difference between heights of left and right 
     subtrees is more than 2 then this node is not balanced
     so return 0 */
  if((lh - rh >= 2) || (rh - lh >= 2))
    return 0;
     
  /* If this node is balanced and left and right subtrees 
    are balanced then return true */
  else return l&&r;
}

bool haspathsum(struct node* node,int sum)				//  check if root to leaf path has sum of a particular number
{
	if(node==NULL)
	return (sum==0);
	
	else
	{
		bool ans=0;
		int subsum=sum-node->data;
		
		if(subsum==0 && node->left==NULL && node->right==NULL)
		return true;
		
		if(node->left)
		ans=ans || haspathsum(node->left,subsum);
		if(node->right)
		ans=ans || haspathsum(node->right,subsum);
		
		return ans;
	}
}

void print_onepath(int path[],int pathlength);				// utility function to print all root to leaf paths

void printpath(struct node* root,int path[],int pathlength)			// function to print all root to leaf paths	
{
	if(root==NULL)
	return;
	
	path[pathlength]=root->data;
	pathlength++;
	
	if(root->left==NULL && root->right==NULL)
	{
		print_onepath(path,pathlength);
	}
	else
	{
		printpath(root->left,path,pathlength);
		printpath(root->right,path,pathlength);
	}
}

void print_onepath(int path[],int pathlength)
{
	for(int i=0;i<pathlength;i++)
	{
		cout<<path[i]<<" ";
	}
	cout<<endl;
}

void doubletree(struct node* node)					//program to create a double tree
{
	if(node==NULL)
	return;
	
	doubletree(node->left);
	doubletree(node->right);
	
	struct node* oldleft;
	oldleft=node->left;
	node->left=newnode(node->data);
	node->left->left=oldleft;
}

int max_width(struct node* root)						//program to find maximum width of a binary tree
{
	if(root==NULL)
	return 0;
	
	queue<struct node*>Q;
	Q.push(root);
	
	int result=0;
	
	while(!Q.empty())
	{
		int count=Q.size();
		
		result=max(result,count);
		
		while(count--)
		{
			struct node* current=Q.front();
			Q.pop();
			if(current->left)
			Q.push(current->left);
			if(current->right)
			Q.push(current->right);
		}
	}
	return result;
}

void printkDistant(struct node* root,int k)				//program to print nodes at k distance from the root node
{
	if(root==NULL)
	return;
	
	if(k==0)
	{
		cout<<root->data<<" ";
		return;
	}
	else
	{
		printkDistant(root->left,k-1);
		printkDistant(root->right,k-1);
	}
}

int maxLevelSum(node * root)					//function to calculate maximum level sum in a binary tree
{
   //Your code here
   if(root==NULL)
   return 0;
   
   queue<struct node*>Q;
   Q.push(root);
   
   int s=0;
   int sum;
   
   while(!Q.empty())
   {
       int count=Q.size();
       sum=0;
       
       while(count--)
       {
           struct node* current=Q.front();
           sum+=current->data;
           Q.pop();
           if(current->left)
           Q.push(current->left);
           if(current->right)
           Q.push(current->right);
       }
       s=max(s,sum);
   }
   return s;
}

stack<int>S;
void kthLargest(node *root, int k)				// program to print kth largest element in a binary tree
{
    //Your code here
    if(root==NULL)
    return;
    
    kthLargest(root->left,k);
    S.push(root->data);
    if(S.size()==k)
    {
        cout<<S.top()<<endl;
        return;
    }
    kthLargest(root->right,k);
}

bool printAncestors(struct node* root,int target)					//  program to print the ancestors of a node of a tree
{
	if(root==NULL)
	return false;
	
	if(root->data==target)
	return true;
	
	if(printAncestors(root->left,target) || printAncestors(root->right,target))
	{
		cout<<root->data<<" ";
		return true;
	}
	
	return false;
}

int toSumTree(struct node* root)					// function to convert a tree into a sumtree
{
	if(root==NULL)
	return 0;
	
	int olddata=root->data;
	
	root->data=toSumTree(root->left)+toSumTree(root->right);
	
	return root->data+olddata;
}

void connectRecur(struct node* root)					// a utility function to connct the nodes of a tree at the same level
{
    if(root==NULL)
    return;
    
    if(root->left)
    root->left->nextRight=root->right;
    
    if(root->right)
    root->right->nextRight=(root->nextRight)?root->nextRight->left:NULL;
    
    connectRecur(root->left);
    connectRecur(root->right);
}

void connect(node *root)				// function to connect all the nodes of a tree at the same level
{
   root->nextRight=NULL;
   
   connectRecur(root);
}

void printLeaves(struct node* root)						// function to print leaves of a binary tree
{
    if ( root )
    {
        printLeaves(root->left);
 
        if ( !(root->left)  &&  !(root->right) )
            printf("%d ", root->data);
 
        printLeaves(root->right);
    }
}
 
// A function to print all left boundry nodes, except a leaf node.
// Print the nodes in TOP DOWN manner
void printBoundaryLeft(struct node* root)
{
    if (root)
    {
        if (root->left)
        {
            // to ensure top down order, print the node
            // before calling itself for left subtree
            printf("%d ", root->data);
            printBoundaryLeft(root->left);
        }
        else if( root->right )
        {
            printf("%d ", root->data);
            printBoundaryLeft(root->right);
        }
        // do nothing if it is a leaf node, this way we avoid
        // duplicates in output
    }
}
 
// A function to print all right boundry nodes, except a leaf node
// Print the nodes in BOTTOM UP manner
void printBoundaryRight(struct node* root)
{
    if (root)
    {
        if ( root->right )
        {
            // to ensure bottom up order, first call for right
            //  subtree, then print this node
            printBoundaryRight(root->right);
            printf("%d ", root->data);
        }
        else if ( root->left )
        {
            printBoundaryRight(root->left);
            printf("%d ", root->data);
        }
       // do nothing if it is a leaf node, this way we avoid
       // duplicates in output
    }
}

// A function to do boundary traversal of a given binary tree
void printBoundary (struct node* root)
{
    if (root)
    {
        printf("%d ",root->data);
 
        // Print the left boundary in top-down manner.
        printBoundaryLeft(root->left);
 
        // Print all leaf nodes
        printLeaves(root->left);
        printLeaves(root->right);
 
        // Print the right boundary in bottom-up manner
        printBoundaryRight(root->right);
    }
}

int level_of_node(struct node* root,int data,int level)			// function to calculate level of a node
{
	if(root==NULL)
	return 0;
	
	if(root->data==data)
	return level;
	
	if(data<root->data)
	return level_of_node(root->left,data,level+1);
	
	else
	return level_of_node(root->right,data,level+1);
}
 
void iterative_preorder(struct node* root)						// iterative function to print preorder traversal
{
	if(root==NULL)
	return;
	
	stack<struct node*>S;
	S.push(root);
	while(!S.empty())
	{
		struct node* current=S.top();
		S.pop();
		cout<<current->data<<" ";
		
		if(current->right)
		S.push(current->right);
		if(current->left)
		S.push(current->left);
	}
}

void inorder_iterative(struct node* root)					// iterative function to print inorder travesal of a tree
{
	if(root==NULL)
	return;
	
	stack<struct node*>S;
	struct node* current=root;
	int done=0;
	while(!done)
	{
		if(current!=NULL)
		{
			S.push(current);
			current=current->left;
		}
		else
		{
			if(!S.empty())
			{
				struct node* curr=S.top();
				cout<<curr->data<<" ";
				S.pop();
				
				current=curr->right;
			}
			else
			{
				done=1;
			}
		}
	}
}

void iterative_postorder(struct node* root)				// iterative function to print postorder of a tree using two stacks
{
	if(root==NULL)
	return;
	
	stack<struct node*>S1;
	stack<struct node*>S2;
	
	S1.push(root);
	while(!S1.empty())
	{
		struct node* curr=S1.top();
		S2.push(curr);
		S1.pop();
		
		if(curr->left)
		S1.push(curr->left);
		if(curr->right)
		S1.push(curr->right);
	}
	
	while(!S2.empty())
	{
		struct node* curr=S2.top();
		cout<<curr->data<<" ";
		S2.pop();
	}
}

void reverse_levelorder(struct node* root)			// function to print reverse level order traversal of a tree
{
	if(root==NULL)
	return;
	
	queue<struct node*>Q;
	stack<struct node*>S;
	Q.push(root);
	while(!Q.empty())
	{
		struct node* curr=Q.front();
		Q.pop();
		S.push(curr);
		
		if(curr->right)
		Q.push(curr->right);
		if(curr->left)
		Q.push(curr->left);
	}
	while(!S.empty())
	{
		struct node* curr=S.top();
		cout<<curr->data<<" ";
		S.pop();
	}
}

struct node* least_common_ancestor(struct node* root,int n1,int n2)			// function to find the least common ancestor of two nodes of a binary search tree
{
	if(root==NULL)
	return NULL;
	
	if(root->data>n1 && root->data>n2)
	return least_common_ancestor(root->left,n1,n2);
	
	else if(root->data<n1 && root->data<n2)
	return least_common_ancestor(root->right,n1,n2);
	
	return root;
}

struct node* remove_outsiderange(struct node* root,int min,int max)
{
	if(root==NULL)
	return NULL;
	
	root->left=remove_outsiderange(root->left,min,max);
	root->right=remove_outsiderange(root->right,min,max);
	
	if(root->data<min)
	{
		struct node* temp=root->right;
		delete(root);
		return temp;
	}
	if(root->data>max)
	{
		struct node* temp=root->left;
		delete(root);
		return temp;
	}
	
	return root;
}

int count_halfnodes(struct node* root)					// function to count half nodes in a tree(nodes who have only one child)
{
	if(root==NULL)
	return 0;
	
	int count=0;
	queue<struct node*>Q;
	Q.push(root);
	while(!Q.empty())
	{
		struct node* temp=Q.front();
		Q.pop();
		if(temp->left && !temp->right || !temp->left && temp->right)
		count++;
		
		if(temp->left)
		Q.push(temp->left);
		if(temp->right)
		Q.push(temp->right);
	}
	return count;
}

void levelorder_spiral(struct node* root)					// function to print level order traversal in spiral form
{
	if(root==NULL)
	return;
	
	stack<node*>s1;
	stack<node*>s2;
	s1.push(root);
	while(!s1.empty() || !s2.empty())
	{
		if(!s1.empty())
		{
			while(!s1.empty())
			{
				struct node* temp=s1.top();
				cout<<temp->data<<" ";
				if(temp->left)
				s2.push(temp->left);
				if(temp->right)
				s2.push(temp->right);
			}
		}
		
		if(!s2.empty())
		{
			while(!s2.empty())
			{
				struct node* temp=s2.top();
				cout<<temp->data<<" ";
				if(temp->right)
				s1.push(temp->right);
				if(temp->left)
				s1.push(temp->left);
			}
		}
	}
}

void count_evenleaves(struct node* root,int &count)			// function to count number of even valued nodes
{
	if(root==NULL)
	return ;
	
	count_evenleaves(root->left,count);
	count_evenleaves(root->right,count);
	
	if(root->data%2==0)
	count++;
}
				
bool kdistant(node* root,int k,int &count)						// function to count number of nodes which are at k distance from any leaf nodes
{
    if(root==NULL)
    return false;
    
    if(root->left==NULL && root->right==NULL)
    {
        if(k==0)
        return true;
    }
    
    if(kdistant(root->left,k-1,count))
    {
    	count++;
    	return true;
	}
    
    
    if(kdistant(root->right,k-1,count))
    {
    	count++;
    	return true;
	}
    
    return false;
}

void kDistantFromLeafUtil(node* node,int k)
{
    int count=0;
    kdistant(node,k,count);
    cout<<count<<" ";
}

bool checkleaves_samelevel(node* root,int *maxlevel,int level)
{
	if(root==NULL)
	return true;
	
	if(root->left==NULL && root->right==NULL)				// function to check if all leaves of a tree are at same level or not
	{
		if(*maxlevel==0)
		{
			*maxlevel=level;
			return true;
		}
		
		return (level==*maxlevel);
	}
	
	return checkleaves_samelevel(root->left,maxlevel,level+1) && checkleaves_samelevel(root->right,maxlevel,level+1);
}

int search(int *a,int x,int n)
{
    for(int i=0;i<n;i++)
    {
        if(a[i]==x)
        return i;
    }
}
void printPostOrder(int in[], int pre[], int n)				// function to print postorder from inorder and preorder
{															// inorder- 4 2 5 1 3 6  	preorder-1 2 4 5 3 6
    int root=search(in,pre[0],n);
    
    if(root!=0)
    printPostOrder(in,pre+1,root);
    
    if(root!=n-1)
    printPostOrder(in+root+1,pre+root+1,n-root-1);
    
    cout<<pre[0]<<" ";
}

node* nextRight(node* root,int data)				// function to find nextright of a particular node
{
	if(root==NULL)
	return NULL;
	
	queue<node*>qn;
	queue<int>ql;
	
	int level=0;
	qn.push(root);
	ql.push(level);
	while(!qn.empty())
	{
		node* curr=qn.front();
		qn.pop();
		level=ql.front();
		ql.pop();
		if(curr->data==data)
		{
			if(ql.size()==0 || ql.front()!=level)
			return NULL;
			else
			return qn.front();
		}
		
		if(curr->left)
		{
			qn.push(curr->left);
			ql.push(level+1);
		}
		if(curr->right)
		{
			qn.push(curr->right);
			ql.push(level+1);
		}
	}
	return NULL;
}

node* nextLeft(node* root,int data)				// function to find nextleft of a particular node
{
	if(root==NULL)
	return NULL;
	
	queue<node*>qn;
	queue<int>ql;
	
	int level;
	qn.push(root);
	ql.push(level);
	while(!qn.empty())
	{
		node* curr=qn.front();
		qn.pop();
		level=ql.front();
		ql.pop();
		if(curr->data==data)
		{
			if(ql.size()==0 || ql.front()!=level)
			return NULL;
			else
			return qn.front();
		}
		
		if(curr->right)
		{
			qn.push(curr->right);
			ql.push(level+1);
		}
		if(curr->left)
		{
			qn.push(curr->left);
			ql.push(level+1);
		}
	}
	return NULL;
}

void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

//Given tree: 
//               a
//            /     \
//           b       c
//         /  \     /  \
//        d    e    f    g
//       / \  / \  / \  / \
//       h  i j  k l  m  n  o 
//
//Modified tree:
//  	       	 a
//            /     \
//           c       b
//         /  \     /  \
//        d    e    f    g
//       / \  / \  / \  / \
//      o  n m  l k  j  i  h 

void reverseAux(node* root1,node* root2,int level)
{
    if(root1==NULL || root2==NULL)
    return;
    
    if(level%2==0)
    {
        swap(&(root1->data),&(root2->data));
    }
    
    reverseAux(root1->left,root2->right,level+1);
    reverseAux(root1->right,root2->left,level+1);
}

void reverseAlternate(node *root)
{
    //Your code here
    reverseAux(root->left,root->right,0);
}

bool isLeaf(node* root)
{
	if(root==NULL)
	return false;
	
	if(root->left==NULL && root->right==NULL)
	return true;
	
	return false;
}

bool isSumTree(node* root)
{
	if(root==NULL || isLeaf(root))
	return true;
	
	int ls,rs;
	
	if(isSumTree(root->left) && isSumTree(root->right))
	{
		if(root->left==NULL)
		ls=0;
		else if(isLeaf(root->left))
		ls=root->left->data;
		else
		ls=2*root->left->data;
		
		if(root->right==NULL)
		rs=0;
		else if(isLeaf(root->right))
		rs=root->right->data;
		else
		rs=2*root->right->data;
		
		return (root->data==ls+rs);
	}
	
	return false;
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
	cout<<"preorder traversal of tree"<<endl;
	preorder(root);					//preorder traversal function of a tree
	cout<<endl;
	cout<<"enter to search a element and show its parent"<<endl;
	cin>>x;
	cout<<"its parent"<<endl;
	struct node* a=parent(root,x);				//function to find a node and print its parent
	if(a)
	cout<<a->data;
	int height=0;
	cout<<diameter(root,&height);				//function to find diameter of a tree by a optimized code
	cout<<isBalanced(root,&height);				//function to check if a tree id=s balanced by a optimized code
	kthLargest(root,3);							//function to find kth largest element in a tree
	cout<<level_of_node(root,3,1);				//functio to find level of a node in a tree
	cout<<endl;
	int c=0;
	count_evenleaves(root,c);
	cout<<c<<endl;
}
