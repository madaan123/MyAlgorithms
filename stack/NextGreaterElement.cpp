#include<bits/stdc++.h>
using namespace std;

/*
Given an array, print the Next Greater Element (NGE) for every element.
The Next greater Element for an element x is the first greater element on the right side of x in array. 
Elements for which no greater element exist, consider next greater element as -1.

Examples:
[2, 3, 10, 6, 4, 8, 1] -> [3, 10, -1, 8, 8, -1, -1]
*/

int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	cin>>a[i];
	stack<int>S;
	S.push(0);
	for(int i=1;i<n;i++)
	{
		while(a[i]>a[S.top()])
		{
			a[S.top()]=a[i];
			S.pop();
			if(S.empty())
			break;
		}
		
		S.push(i);
	}
	while(!S.empty())
	{
		a[S.top()]=-1;
		S.pop();
	}
	for(int i=0;i<n;i++)
	cout<<a[i]<<" ";
	cout<<endl;
}
