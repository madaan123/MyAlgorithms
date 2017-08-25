#include<bits/stdc++.h>
using namespace std;

/*
	Program to find maximum size rectangle consisting of all ones
	for example:-
	1 1 1 1
	0 0 1 1
	1 1 0 1
	1 1 1 1
	
	maximum size is 4
	1 1 1 1  in first row or in last column
*/
int MaxArea(int a[],int n)
{
	stack<int>S; 
	int area;
	int maxArea=-1;
	int top,i;
	S.push(0);
	for(i=1;i<n;i++)
	{
		if(a[i]>=a[S.top()])
		{
			S.push(i);
		}
		else
		{
			while(!S.empty() && a[i]<=a[S.top()])
			{
				top=S.top();
				S.pop();
				if(!S.empty())
				{
					area=a[top]*(i-S.top()-1);
				}
				else
				{
					area=i*a[top];
					//break;
				}
				cout<<area<<" ";
				if(area>maxArea)
				{
					maxArea=area;
				//	cout<<maxArea<<endl;
				}
			}
			S.push(i);
		}
	}
	
	while(!S.empty())
	{
				top=S.top();
				S.pop();
				if(!S.empty())
				{
					area=a[top]*(i-S.top()-1);
				}
				else
				{
					area=i*a[top];
				}
				//cout<<area<<"";
				if(area>maxArea)
				{
					maxArea=area;
				}
	}
	return maxArea;
}

void printAux(int aux[],int n)
{
	for(int i=0;i<n;i++)
	cout<<aux[i]<<" ";
	cout<<endl;
}

int MaxsizeRectangle(int **matrix,int m,int n)
{
	int aux[n];
	int maxarea=0;
	for(int i=0;i<n;i++)
	aux[i]=matrix[0][i];
	printAux(aux,n);
	for(int i=1;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(matrix[i][j]==0)
			aux[j]=0;
			else
			aux[j]=aux[j]+1;
		}
		printAux(aux,n);
		maxarea=max(maxarea,MaxArea(aux,n));
	}
	return maxarea;
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
		{
			cin>>matrix[i][j];
		}
	}
	
	cout<<MaxsizeRectangle((int**)matrix,m,n)<<endl;
	//cout<<MaxArea(a,n)<<endl;
}
