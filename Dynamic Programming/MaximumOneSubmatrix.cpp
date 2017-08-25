#include<iostream>
using namespace std;

int min(int a,int b,int c)
{
	return min(a,min(b,c));
}

int MaxSizeSubmatrix(int** matrix,int m,int n)
{
	int mat[m][n];
	
	for(int i=0;i<m;i++)
	{
		mat[0][i]=matrix[0][i];
	}
	
	for(int i=1;i<n;i++)
	{
		mat[i][0]=matrix[i][0];
	}
	
	int maxm=0;
	
	for(int i=1;i<m;i++)
	{
		for(int j=1;j<n;j++)
		{
			if(matrix[i][j]==0)
			mat[i][j]=0;
			
			else
			{
				mat[i][j]=min(mat[i-1][j-1],mat[i-1][j],mat[i][j-1])+1;
				if(mat[i][j]>maxm)
				maxm=mat[i][j];
			}
		}
	}
	return maxm;
}

int main()
{
	int m,n;
	cin>>m>>n;
	int** matrix=new int*[m];
	for(int i=0;i<m;i++)
	{
		matrix[i]=new int[n];
	}
	
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		cin>>matrix[i][j];
	}
	
	cout<<MaxSizeSubmatrix((int**)matrix,m,n)<<endl;
}
