#include<bits/stdc++.h>
using namespace std;

int rodCutting(int price[],int n)
{
	int val[n+1];
	val[0]=0;
	
	int maxval;
	for(int i=1;i<=n;i++)
	{
		maxval=INT_MIN;
		for(int j=0;j<i;j++)
		maxval=max(maxval,price[j]+val[i-j-1]);
		val[i]=maxval;
	}
	return val[n];
}

int main()
{
	int n;
	cin>>n;
	int price[n];
	for(int i=0;i<n;i++)
	cin>>price[i];
	cout<<rodCutting(price,n);
}
