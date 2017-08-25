#include<bits/stdc++.h>
using namespace std;

/*
Given an array of integers and a sum, the task is to count all subsets of given array with sum equal to given sum.

no.of elements in a array-6
array elements-2 3 5 6 8 10
Required sum-10

output- 3
{
{2,3,5}
{8,2}
{10}
}
*/

int SubsetSum(int a[],int n,int sum)
{
    int dp[sum+1][n+1];
    
    for(int i=0;i<=n;i++)
    dp[0][i]=1;
    
    for(int i=1;i<=sum;i++)
    dp[i][0]=0;
    
    for(int i=1;i<=sum;i++)
    {
        for(int j=1;j<=n;j++)
        {
            int x=dp[i][j-1];
            
            int y=(i>=a[j-1])?dp[i-a[j-1]][j-1]:0;
            
            dp[i][j]=x+y;
        }
    }
    /*
    for(int i=0;i<=sum;i++)
    {
        for(int j=0;j<=n;j++)
        cout<<dp[i][j]<<" ";
        cout<<endl;
    }
    */
    return dp[sum][n];
}

int main()
 {
	int t;
        cin>>t;
       while(t--)
       {
               int n,sum;
               cin>>n;
               int a[n];
               for(int i=0;i<n;i++)
               cin>>a[i];
               cin>>sum;
               cout<<SubsetSum(a,n,sum)<<endl;
        }
	return 0;
}
