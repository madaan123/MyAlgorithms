#include<iostream>
using namespace std;

void merge(int *a,int *aux,int low,int mid,int high)			// mergesort function to merge the two sorted subarrays
{
	for(int k=low;k<=high;k++)
	aux[k]=a[k];
	
	int i=low;
	int j=mid+1;
	for(int k=low;k<=high;k++)
	{
		if (i>mid)  a[k]=aux[j++];
		else if (j>high) a[k]=aux[i++];
		else if (aux[j]<aux[i]) a[k]=aux[j++];
		else a[k]=aux[i++];
	}
}

void mergesort(int *a,int *aux,int low,int high)			// mergesort function to implement sort by divide and conquer method
{
	if(high<=low) return;
	int mid=low+(high-low)/2;
	mergesort(a,aux,low,mid);
	mergesort(a,aux,mid+1,high);
	
	merge(a,aux,low,mid,high);
}

bool binary_search(int *a,int low,int high,int key)				// binary searching of a key in a sorted array
{
	int mid;
	while(low<high)
	{
		mid=low+(high-low)/2;
		if(a[mid]==key)
		return true;
		else if(a[mid]>key)
		high=mid-1;
		else if(a[mid]<key)
		low=mid+1;
	}
	return false;
}

int main()
{
	int n;
	cin>>n;
	int a[n];
	int aux[n];
	for(int i=0;i<n;i++)
	cin>>a[i];
	
	mergesort(a,aux,0,n-1);
	for(int i=0;i<n;i++)
	cout<<a[i]<<" ";
	cout<<endl;
	
	int x;
	cout<<"Enter a element to search in a array"<<endl;
	cin>>x;
	cout<<binary_search(a,0,n-1,x);
}
