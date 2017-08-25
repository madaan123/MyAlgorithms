#include<iostream>
using namespace std;

/*
Given a value N, if we want to make change for N cents, and we have infinite supply of each of S = { S1, S2, .. , Sm} valued coins,
how many ways can we make the change? The order of coins doesn’t matter.

For example, for N = 4 and S = {1,2,3}, there are four solutions: {1,1,1,1},{1,1,2},{2,2},{1,3}.
So output should be 4. For N = 10 and S = {2, 5, 3, 6}, there are five solutions: {2,2,2,2,2}, {2,2,3,3}, {2,2,6}, {2,3,5} and {5,5}. 
So the output should be 5.
*/

int ways(int coins[],int value,int n)
{
	int dp[value+1][n];
	for(int i=0;i<n;i++)
	dp[0][i]=1;
	
	for(int i=1;i<=value;i++)
	{
		for(int j=0;j<n;j++)
		{
			int x=(i>=coins[j])?dp[i-coins[j]][j]:0;
			
			int y=(j>0)?dp[i][j-1]:0;
			
			dp[i][j]=x+y;
		}
	}
	return dp[value][n-1];
}

int main()
{
	int n,value;
	cin>>n;
	int coins[n];
	for(int i=0;i<n;i++)
	cin>>coins[i];
	cin>>value;
	cout<<ways(coins,value,n);
}
