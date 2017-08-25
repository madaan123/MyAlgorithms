#include<bits/stdc++.h>
using namespace std;

/*
Given an array of distinct integers, find length of the longest subarray
which contains numbers that can be arranged in a continuous sequence.

Examples:
Input: arr[] = {10, 12, 11};
Output: 3

Input: arr[] = {14, 12, 11, 20};
Output: 2
*/

int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	cin>>a[i];
	int min,max;
	int ans=1;
	for(int i=0;i<n;i++)
	{
		min=a[i];
		max=a[i];
		for(int j=i+1;j<n;j++)
		{
			if(a[j]>max)
			max=a[j];
			if(a[j]<min)
			min=a[j];
			
			if((max-min)==j-i && (j-i+1)>ans)
			ans=j-i+1;
		}
	}
	cout<<ans<<endl;
}
