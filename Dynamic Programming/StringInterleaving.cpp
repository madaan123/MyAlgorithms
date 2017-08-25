#include<bits/stdc++.h>
using namespace std;

bool StringInterleav(string s1,string s2,string pattern,int l1,int l2)
{
	bool dp[l2+1][l1+1];
	
	memset(dp,false,sizeof(dp));
	
	dp[0][0]=true;
	
	for(int i=1;i<=l1;i++)
	{
		if(s1[i-1]==pattern[i-1])
		dp[0][i] |= dp[0][i-1];
	}
	
	for(int i=1;i<=l2;i++)
	{
		if(s2[i-1]==pattern[i-1])
		dp[i][0] |= dp[i-1][0];
	}
	
	for(int i=1;i<=l2;i++)
	{
		for(int j=1;j<=l1;j++)
		{
			if(s2[i-1]==pattern[i+j-1])
			dp[i][j] |= dp[i-1][j];
			if(s1[j-1]==pattern[i+j-1])
			dp[i][j] |= dp[i][j-1];
		}
	}
	
	for(int i=0;i<=l2;i++)								// 	uncomment to see the dp matrix that is formed
	{
		for(int j=0;j<=l1;j++)
		cout<<dp[i][j]<<" ";
		cout<<endl;
	}
}

int main()
{
	string s1,s2,pattern;
	cin>>s1>>s2>>pattern;
	
	cout<<StringInterleav(s1,s2,pattern,s1.length(),s2.length());
}
