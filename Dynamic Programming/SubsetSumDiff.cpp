#include<bits/stdc++.h>
using namespace std;
/*
Partition a set into 2 subsets so that difference between the subset sum is minimum
ex:-
1 6 5 11
output=1
{1,11},{6,5}
*/

int SubsetSum(int a[],int sum,int n)
{
	bool dp[sum+1][n+1];
	
	for(int i=0;i<=n;i++)
	dp[0][i]=true;
	
	for(int i=1;i<=sum;i++)
	dp[i][0]=false;
	
	for(int i=1;i<=sum;i++)
	{
		for(int j=1;j<=n;j++)
		{
			dp[i][j]=dp[i][j-1];
			if(i>=a[j-1])
			{
				dp[i][j]=dp[i][j] || dp[i-a[j-1]][j-1];
			}
		}
	}
	
	for(int i=sum;i>=0;i--)
	{
		if(dp[i][n])
		return i;
	}
}

int main()
{
	int n;
	cin>>n;
	int a[n];
	int sum=0;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		sum+=a[i];
	}
	int k=SubsetSum(a,sum/2,n);
	cout<<sum-(2*k)<<endl;
}
