#include<iostream>
using namespace std;

int nCk(int n,int k)
{
	int bin[n+1][k+1];
	
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=min(i,k);j++)
		{
			if(j==0 || j==i)
			bin[i][j]=1;
			
			else
			bin[i][j]=bin[i-1][j-1]+bin[i-1][j];
		}
	}
	return bin[n][k];
}

int main()
{
	int n,k;
	cin>>n>>k;
	if(k>n/2);
	k=n-k;
	cout<<nCk(n,k)<<endl;
}
