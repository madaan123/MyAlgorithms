#include<bits/stdc++.h>
using namespace std;

/*
Given a N X N  matrix Matrix[N][N] of positive integers.  There are only three possible moves from a cell Matrix[r][c].

1. Matrix[r+1][c]

2. Matrix[r+1][c-1]

3. Matrix[r+1][c+1]

Starting from any column in row 0, return the largest sum of any of the paths up to row N-1.
*/

int MaxPath(int** a,int n)
{
	int val[n][n];
	
	for(int i=0;i<n;i++)
	val[n-1][i]=a[n-1][i];
	
	int maxvalue=0;
	int curr;
	
	for(int i=n-2;i>=0;i--)
	{
		for(int j=n-1;j>=0;j--)
		{
			curr=a[i][j];
			if(i+1<n)
			curr=max(curr,a[i][j]+val[i+1][j]);
			if(j+1<n)
			curr=max(curr,a[i][j]+val[i+1][j]);
			if(j-1>=0)
			curr=max(curr,a[i][j]+val[i+1][j-1]);
			
			val[i][j]=curr;
			maxvalue=max(maxvalue,curr);
		}
	}
	
	/*
	for(int i=0;i<n;i++)
	{											// Uncomment to see path matrix 
		for(int j=0;j<n;j++)
		{
			cout<<val[i][j]<<" ";
		}
		cout<<endl;
	}
	*/
	return maxvalue;
}

int main()
 {
	int t;
        cin>>t;
       while(t--)
       {
               int n;
               cin>>n;
               int** matrix=new int*[n];
               for(int i=0;i<n;i++)
               {
                   matrix[i]=new int[n];
               }
               
               for(int i=0;i<n;i++)
               {
               		for(int j=0;j<n;j++)
               		{
               			cin>>matrix[i][j];
					}
			   }
			   cout<<MaxPath((int**)matrix,n);
        }
	return 0;
}
