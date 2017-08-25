#include<bits/stdc++.h>
using namespace std;

int LIS(int a[],int n)
{
	int *lis=new int[n];
	for(int i=0;i<n;i++)
	lis[i]=1;
	
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<i;j++)
		{
			if(a[i]<a[j] && lis[j]+1>lis[i])
			lis[i]=lis[j]+1;
		}
	}
	
	int maxm=lis[0];
	for(int i=1;i<n;i++)
	{
		maxm=max(maxm,a[i]);
	}
	
	delete(lis);
	return maxm;
}

int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	cin>>a[i];
	int l=LIS(a,n);
}
