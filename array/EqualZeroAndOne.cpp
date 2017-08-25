#include<bits/stdc++.h>
using namespace std;

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
	{
		if(a[i]==1)
		sum[i]=sum[i-1]+1;
		else
		sum[i]=sum[i-1]-1;
	}
	
	map<int,int>seen;
	int ans=0;
	for(int i=0;i<n;i++)
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
	
	/*
	for(int i=0;i<n;i++)				//	Uncomment to see sum and hashed entries of the sum
	cout<<sum[i]<<" ";cout<<endl;
	for(int i=0;i<n;i++)
	cout<<seen[sum[i]]<<" ";cout<<endl;
	*/
	
	cout<<ans<<endl;
}
