#include<iostream>
using namespace std;

void swap(int *a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}

void swim(int *a,int k)						// swimming of a new node entering in a heap at its end
{
	while(k>1 && a[k/2]<a[k])
	{
		swap(&a[k],&a[k/2]);
		k=k/2;
	}
}

void insert(int *a,int key,int *N)			// function to insert a new node into a heap
{
	a[++(*N)]=key;
	swim(a,*N);
}

void sink(int *a,int k,int *N)
{
	while(2*k<=(*N))
	{
		int j=2*k;
		if(j<(*N) && a[j]<a[j+1]) j++;
		if(a[k]>a[j]) break;
		swap(&a[k],&a[j]);
		k=j;
	}
}

int delMax(int *a,int *N)					// extracting the maximum element of a heap
{
	int max=a[1];
	swap(&a[1],&a[(*N)--]);
	sink(a,1,N);
	return max;
}

bool isEmpty(int *N)					// function to check whether heap is empty or not
{
	return (*N==0);
}

void heap_sort(int *a,int *N)			// sorting of a array by heap sort
{
	for(int k=(*N)/2;k>=1;k--)			// generation of a max heap
	{
		sink(a,k,N);
	}
	while(*N)						// applying soting procedure by swapping first and last element of a heap and regenerating a maxheap
	{
		swap(&a[1],&a[(*N)--]);
		sink(a,1,N);
	}
}

void decrease_key(int *a,int pos,int value)			// function to decrease the key of a cell in a array
{
	a[pos]=value;
	swim(a,pos);
}

int main()
{
	int n;
	cin>>n;
	int k=n;
	int *a=new int[n];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	heap_sort(a,&n);
	for(int i=1;i<=k;i++)
	cout<<a[i]<<" ";
}
