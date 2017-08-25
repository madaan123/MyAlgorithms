#include<bits/stdc++.h>
using namespace std;

int mincoins(int a[],int n,int V)
{
	int coins[V+1];
	for(int i=1;i<=V;i++)
	coins[i]=INT_MAX;
	
	coins[0]=0;
	for(int i=1;i<=V;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(a[j]<=i)
			{
				if(coins[i-a[j]]!=INT_MAX && coins[i-a[j]]+1<coins[i])
				coins[i]=coins[i-a[j]]+1;
			}
		}
	}
	return coins[V];
}

int main()
{
	int n,V;
	cin>>n>>V;
	int a[n];
	for(int i=0;i<n;i++)
	cin>>a[i];
	cout<<mincoins(a,n,V);
}
