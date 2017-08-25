#include<iostream>
using namespace std;

int edgelength(string s1,string s2,int n,int m)
{
	int v[n+1][m+1];
	for(int i=0;i<=m;i++)
	v[0][i]=i;
	for(int i=1;i<=n;i++)
	v[i][0]=i;
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(s1[i]==s2[j])
			v[i][j]=v[i-1][j-1];
			else
			{
				v[i][j]=v[i][j-1];			// check for minimum of insert,delete and replace options and add one to it
				
				if(v[i-1][j]<v[i][j])
				v[i][j]=v[i][j-1];
				
				if(v[i-1][j-1]<v[i][j])
				v[i][j]=v[i-1][j-1];
				
				v[i][j]++;
			}
		}
	}
	return v[n][m];
}

int main()
{
	string s1,s2;
	cin>>s1>>s2;
	int n,m;
	n=s1.length();
	m=s2.length();
	cout<<edgelength(s1,s2,n,m);
}
