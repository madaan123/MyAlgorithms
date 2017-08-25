#include<iostream>
using namespace std;

int min(int a,int b,int c)
{
	return min(a,min(b,c));
}

int MinOperations(string s1,string s2,int n,int m)
{
	int dp[n+1][m+1];
	
	for(int i=0;i<=m;i++)
	dp[0][i]=2*i;
	
	for(int i=1;i<=n;i++)
	dp[i][0]=2*i;
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(s1[i-1]==s2[j-1])
			dp[i][j]=dp[i-1][j-1];
			
			else
			dp[i][j]=min(dp[i-1][j-1]+3,dp[i][j-1]+2,dp[i-1][j]+2);
		}
	}
	
	/*
	for(int i=0;i<=n;i++)				Uncomment to see the dynamic programming matrix
	{
		for(int j=0;j<=m;j++)
		cout<<dp[i][j]<<" ";
		cout<<endl;
	}
	*/
	
	return dp[n][m];
}

int main()
{
	string s1,s2;
	cin>>s1>>s2;
	cout<<MinOperations(s1,s2,s1.length(),s2.length());
}
