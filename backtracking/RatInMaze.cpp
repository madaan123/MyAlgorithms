#include<bits/stdc++.h>
using namespace std;

bool path(int** maze,int n,int l,int r)
{
	if(l==n-1 && r==n-1)
	{
		maze[l][r]=2;
		return true;
	}
	
	if(l<0 || r<0 || l>=n || r>=n || maze[l][r]!=1)
	return false;
	
	maze[l][r]=2;
	
	if(path(maze,n,l+1,r))
	return true;
	
	if(path(maze,n,l,r+1))
	return true;
	
	if(path(maze,n,l-1,r))
	return true;
	
	if(path(maze,n,l,r-1))
	return true;
	
	maze[l][r]=1;
	
	return false;
}

void printMaze(int** maze,int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<maze[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}

int main()
{
	int n;
	cin>>n;
	
	int** maze=new int*[n];
	for(int i=0;i<n;i++)
	{
		maze[i]=new int[n];
	}
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		cin>>maze[i][j];
	}
	
	/*
	maze[0][0] = 1;
	maze[1][0] = 1;
	maze[2][0] = 1;
	maze[3][0] = 1;
	maze[4][0] = 1;
	maze[1][1] = 1;
	maze[0][2] = 1;
	maze[1][2] = 1;
	maze[0][3] = 1;
	maze[2][3] = 1;
	maze[3][3] = 1;
	maze[4][3] = 1;
	maze[0][4] = 1;
	maze[1][4] = 1;
	maze[2][4] = 1;
	maze[4][4] = 1;
	*/
	printMaze((int**)maze,n);
	
	if(path((int**)maze,n,0,0))
	{
		cout<<"Yes Path is available"<<endl;
		printMaze((int**)maze,n);
	}
	
	else
	cout<<"No path available"<<endl;
}
