#include<iostream>
using namespace std;

int maxsum_subarray(int a[],int n)
{
	int maxsum=a[0];
	int currsum=a[0];
	for(int i=1;i<n;i++)
	{
		currsum=max(a[i],currsum+a[i]);
		maxsum=max(maxsum,currsum);
	}
	return maxsum;
}

int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	cin>>a[i];
	
	cout<<maxsum_subarray(a,n);
}
