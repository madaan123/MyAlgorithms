#include<bits/stdc++.h>
using namespace std;

int main()
{
	int m,n;
	cin>>m>>n;
	int a[m][n];
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		cin>>a[i][j];
	}
	int k=0,l=0;
	stack<int> S;
	/*  k - starting row index
        m - ending row index
        l - starting column index
        n - ending column index
    */
	while(k<m && l<n)
	{
		for(int i=l;i<n;i++)			// printing the first row of a array
		{
			S.push(a[k][i]);
		}
		k++;							// reducing the topmost row from the array
		for(int i=k;i<m;i++)
		{
			S.push(a[i][n-1]);			// printing the last column of a array
		}
		n--;								// reducing last column from the array
		if(k<m)
		{
			for(int i=n-1;i>=l;i--)
			{
				S.push(a[m-1][i]);		// printing last row of the reduced array
			}
			m--;							// reducing the last row of the array
		}
		if(l<n)
		{
			for(int i=m-1;i>=k;i--)
			{
				S.push(a[i][l]);			// printing the first column of the reduced array
			}
			l++;							// reducing the first column of the array
		}
	}
	
	while(!S.empty())
	{
		cout<<S.top();
		S.pop();
	}
}
