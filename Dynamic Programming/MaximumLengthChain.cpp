#include<bits/stdc++.h>
using namespace std;

struct chain{
	int start;
	int end;
	int length;
};

bool comparator(chain c1,chain c2)
{
	return c1.end<c2.end;
}

int maxmLength(chain c[],int n)
{
	sort(c,c+n,comparator);
	int dp[n];
	dp[0]=c[0].length;
	int curr;
	for(int i=1;i<n;i++)
	{
		curr=c[i].length;
		for(int k=i-1;k>=0;k--)
		{
			if(c[k].end<c[i].start)
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
	chain c[n];
	for(int i=0;i<n;i++)
	{
		cin>>c[i].start;
		cin>>c[i].end;
		c[i].length=c[i].end-c[i].start+1;
	}
	cout<<maxmLength(c,n)<<endl;
}
