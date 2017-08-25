#include<bits/stdc++.h>
using namespace std;

struct job{
	int start;
	int end;
	int profit;
};

bool comparator(job j1,job j2)
{
	return j1.end<j2.end;
}

int maxmProfit(job j[],int n)
{
	sort(j,j+n,comparator);
	int dp[n];
	dp[0]=j[0].profit;
	int curr;
	for(int i=1;i<n;i++)
	{
		curr=j[i].profit;
		for(int k=i-1;k>=0;k--)
		{
			if(j[k].end<=j[i].start)
			{
				curr+=dp[k];
				break;
			}
		}
		dp[i]=max(curr,dp[i-1]);
	}
	return dp[n-1];
}

int main()
{
	int n;
	cin>>n;
	job j[n];
	for(int i=0;i<n;i++)
	{
		cin>>j[i].start;
		cin>>j[i].end;
		cin>>j[i].profit;
	}
	cout<<maxmProfit(j,n)<<endl;
}
