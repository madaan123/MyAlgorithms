#include<iostream>
using namespace std;
#define n 4

void printsolution(int a[n][n])
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		cout<<a[i][j]<<" ";
		cout<<endl;
	}
}

bool issafe(int a[n][n],int row,int col)
{
	int i,j;
	for(int i=0;i<col;i++)
	if(a[row][i])
	return false;
	
	for(i=row, j=col;i>=0 && j>=0;i--,j--)
	if(a[i][j])
	return false;
	
	for(i=row, j=col;i<n && j>=0;i++,j--)
	if(a[i][j])
	return false;
	
	return true;
}

bool solveNQutil(int a[n][n],int col)
{
	if(col>=n)
	{
		printsolution(a);
		cout<<endl;
		return true;
	}
	
	for(int i=0;i<n;i++)
	{
		if(issafe(a,i,col))
		{
			a[i][col]=1;
			
			if(solveNQutil(a,col+1))
			return true;
			
			a[i][col]=0;
		}
	}
	
	return false;
}

bool solveNQ()
{
	int a[n][n];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		a[i][j]=0;
	}
	
	if(solveNQutil(a,0)==false)
	{
		cout<<"solution dos not exists"<<endl;
		return false;
	}
	
	printsolution(a);
	return true;
}

int main()
{
	solveNQ();
	return 0;
}
