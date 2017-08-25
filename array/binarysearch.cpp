#include<bits/stdc++.h>
using namespace std;

int binary_search(int a[],int n,int key)
{
	int low=0;
	int high=n-1;
	int mid;
	while(low<=high)
	{
		mid=low+(high-low)/2;
		if(a[mid]==key)
		return mid;
		else if(a[mid]>key)
		high=mid-1;
		else
		low=mid+1;
	}
	return -1;
}

int binarysearch_recursive(int a[],int low,int high,int key)
{
	if(low>high)
	return -1;
	int mid=low+(high-low)/2;
	if(a[mid]==key)
	return mid;
	else if(a[mid]>key)
	return binarysearch_recursive(a,low,mid-1,key);
	else
	return binarysearch_recursive(a,mid+1,high,key);
}

int first_occurence(int a[],int n,int x)
{
	int low=0;
	int high=n-1;
	int result=-1;
	int mid;
	while(low<=high)
	{
		mid=low+(high-low)/2;
		if(a[mid]==x)
		{
			result=mid;
			high=mid-1;
		}
		else if(a[mid]>x)
		high=mid-1;
		else
		low=mid+1;
	}
	return result;
}

int last_occurence(int a[],int n,int x)
{
	int low=0;
	int high=n-1;
	int result=-1;
	int mid;
	while(low<=high)
	{
		mid=low+(high-low)/2;
		if(a[mid]==x)
		{
			result=mid;
			low=mid+1;
		}
		else if(a[mid]>x)
		high=mid-1;
		else
		low=mid+1;
	}
	return result;
}

int count(int a[],int n,int key)
{
	int first=first_occurence(a,n,key);
	if(!first)
	return 0;
	int last=last_occurence(a,n,key);
	return (first-last+1);
}

int array_rotated(int a[],int n)
{
	int low=0;
	int high=n-1;
	int mid,next,prev;
	while(low<=high)
	{
		mid=low+(high-low)/2;
		if(a[low]<=a[high])
		return low;
		next=(mid+1)%n;
		prev=(mid+n-1)%n;
		if(a[mid]>=a[next] && a[mid]>=a[prev])
		return mid;
		else if(a[mid]<=a[high])
		high=mid-1;
		else if(a[mid]>=a[high])
		low=mid+1;
	}
	return -1;
}

int circulararray_search(int a[],int n,int x)
{
	int low,high;
	low=0;
	high=n-1;
	int mid;
	while(low<=high)
	{
		mid=low+(high-low)/2;
		if(a[mid]==x)
		return x;
		else if(a[mid]<=a[high])
		{
			if(x>a[mid] && x<=a[high])
			low=mid+1;
			else
			high=mid-1;
		}
		else
		{
			if(x<a[mid] && x>=a[low])
			high=mid-1;
			else
			low=mid+1;
		}
	}
	return -1;
}

int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	cin>>a[i];
	sort(a,a+n);
}
