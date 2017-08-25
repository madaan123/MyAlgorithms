#include<bits/stdc++.h>
using namespace std;

bool canRepresentPreorder(int a[],int n)
{
	stack<int> S;
	int root=INT_MIN;
	for(int i=0;i<n;i++)
	{
		if(a[i]<root)
		return false;
		
		while(!S.empty() && a[i]>S.top())
		{
			root=S.top();
			S.pop();
		}
		
		S.push(a[i]);
	}
	return true;
}

int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	cin>>a[i];
	cout<<canRepresentPreorder(a,n);
}
