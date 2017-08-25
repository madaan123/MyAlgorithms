#include<iostream>
using namespace std;

void swap(int *a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}

int partition(int *a,int low,int high)					// function to generate a partition in a array for quick sort
{
	int i=low;
	int j=high+1;
	while(true)
	{
		while(a[++i]<a[low])
		if(i==high) break;
		
		while(a[--j]>a[low])
		if(j==low) break;
		
		if(i>=j) break;
		
		swap(&a[i],&a[i]);
	}
	swap(a[low],a[j]);
	return j;
}

int partition_reverse(int *a,int low,int high)
{
	int i=low-1;
	int j=high;
	while(true)
	{
		while(a[++i]>a[high])
		if(i==high) break;
		
		while(a[--j]<a[high])
		if(j==low) break;
		
		if(i>=j) break;
		
		swap(a[i],a[j]);
	}
	swap(a[high],a[i]);
	return j;
}

void quicksort(int *a,int low,int high)					// driver method for quick sort that calls partition to sort the array.
{
	if(low>high) return;
	int p=partition(a,low,high);
	quicksort(a,low,p-1);
	quicksort(a,p+1,high);
}

void quicksort_reverse(int *a,int low,int high)			//	 reverse quick sort of a array
{
	if(low>high) return;
	int p=partition_reverse(a,low,high);
	quicksort(a,low,p-1);
	quicksort(a,p+1,high);
}

int select_kthlargest(int *a,int k,int n)			// function to calculate kth largest element in the array by using the quick sort algo
{
	int low=0;
	int high=n-1;
	while(high>low)
	{
		int j=partition(a,low,high);
		if(j<k) low=j+1;
		else if(j>k) high=j-1;
		else return a[k];
	}
	return a[k];
}

void sort(int *a,int low,int high)				// 3 way partioning quick sort for duplicate entries in a array
{
	if(high<=low) return;
	int lt=low;
	int gt=high;
	int v=a[low];
	int i=low;
	while(i<=gt)
	{
		if(a[i]<v)
		swap(&a[lt++],&a[i++]);
		else if(a[i]>v)
		swap(&a[i],&a[gt--]);
		else i++;
	}
	sort(a,low,lt-1);
	sort(a,gt+1,high);
}

int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	cin>>a[i];
	
	sort(a,0,n-1);
	for(int i=0;i<n;i++)
	cout<<a[i]<<" ";
}
