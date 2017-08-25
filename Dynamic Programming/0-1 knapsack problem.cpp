#include<iostream>
using namespace std;

int knapsack(int val[],int wt[],int W,int n)
{
	int dp[W+1][n+1];
	
	for(int i=0;i<=W;i++)
	{
		for(int j=0;j<=n;j++)
		{
			if(i==0 || j==0)
			dp[i][j]=0;
			
			else if(wt[j-1]<=n)
			dp[i][j]=max(dp[i][j-1],val[j-1]+dp[i-wt[j-1]][j-1]);
			
			else
			dp[i][j]=dp[i][j-1];
		}
	}
	return dp[W][n];
}

int main()
{
	int n;
	cin>>n;
	int val[n],wt[n];
	for(int i=0;i<n;i++)
	cin>>val[i];
	for(int i=0;i<n;i++)
	cin>>wt[i];
	int W;
	cin>>W;
	knapsack(val,wt,W,n);
}
