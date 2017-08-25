#include<iostream>
using namespace std;

int min(int a,int b,int c)
{
	return min(a,min(b,c));
}

int MinPathCost(int** a,int m,int n)
{
	int path[m][n];
	
	path[0][0]=a[0][0];
	for(int i=1;i<n;i++)
	{
		path[0][i]=path[0][i-1]+a[0][i];
	}
	
	for(int i=1;i<m;i++)
	{
		path[i][0]=path[i-1][0]+a[i][0];
	}
	
	for(int i=1;i<m;i++)
	{
		for(int j=1;j<n;j++)
		{
			path[i][j]=min(path[i-1][j],path[i][j-1],path[i-1][j-1])+a[i][j];
		}
	}
	
	/*
	for(int i=0;i<m;i++)			Path Matrix
	{
		for(int j=0;j<n;j++)
		cout<<path[i][j]<<" ";
		cout<<endl;
	}
	*/
	return path[m-1][n-1];
}

int main()
{
	int m,n;
	cin>>m>>n;
	int** a=new int*[m];
	for(int i=0;i<m;i++)
	{
		a[i]=new int[n];
	}
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>a[i][j];
		}
	}
	cout<<MinPathCost((int**)a,m,n);
}
