#include<iostream>
using namespace std;

int ways(int stairs,int m)				// we can climb 1 to m stairs at a time
{
	int ways[stairs+1];
	ways[0]=1;
	ways[1]=1;
	for(int i=2;i<=stairs;i++)
	{
		ways[i]=0;
		for(int j=1;j<=m && j<=i;j++)
		{
			ways[i]+=ways[i-j];				// ways to climb a stair is no of ways to climb that many stairs
		}
	}
	return ways[stairs];
}

int main()
{
	int n,m;
	cin>>n>>m;
	cout<<ways(n,m);
}
