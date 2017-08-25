#include<bits/stdc++.h>
using namespace std;

int mintrials(int n,int k)
{
    int dp[n+1][k+1],res;
    
    for(int i=1;i<=n;i++)
    {
        dp[i][1]=1;
        dp[i][0]=0;
    }
    
    for(int i=1;i<=k;i++)
    {
        dp[1][i]=i;
    }
    
    for(int i=2;i<=n;i++)
    {
        for(int j=2;j<=k;j++)
        {
            dp[i][j]=INT_MAX;
            for(int x=1;x<=j;x++)
            {
                res=1+max(dp[i-1][x-1],dp[i][j-x]);
                if(res<dp[i][j])
                dp[i][j]=res;
            }
        }
    }
    return dp[n][k];
}

int main()
 {
	int t;
        cin>>t;
       while(t--)
       {
               int n,k;
               cin>>n>>k;
               cout<<mintrials(n,k)<<endl;
        }
	return 0;
}
