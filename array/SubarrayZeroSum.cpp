#include<bits/stdc++.h>
using namespace std;

/*
Given an array of integers find length of largest subarray with sum=0
ex:-
15 -2 2 -8 1 7 10 23
output-5
{-2,2,-8,1,7}
*/
int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	cin>>a[i];
	
	int sum[n];
	sum[0]=a[0];
	for(int i=1;i<n;i++)
	sum[i]=sum[i-1]+a[i];
	
	map<int,int>seen;
	int ans=0;
	for(int i=0;i<n;i++)
	{
		if(sum[i]==0)
		{
			ans=i+1;
		}
		else
		{
			if(seen[sum[i]])
			{
				if((i-seen[sum[i]]+1)>ans)
				{
					ans=i-seen[sum[i]]+1;
				}
			}
			else
			{
				seen[sum[i]]=i+1;
			}
		}
	}
	
	for(int i=0;i<n;i++)					// Uncomment to see sum and hashed entries of the sum
	cout<<sum[i]<<" ";cout<<endl;
	for(int i=0;i<n;i++)
	cout<<seen[sum[i]]<<" ";cout<<endl;
	
	cout<<ans<<endl;
}
