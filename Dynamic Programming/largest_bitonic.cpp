#include<iostream>
using namespace std;

int largest_bitonic(int a[],int n)
{
	int inc[n],dec[n];
	
	inc[0]=1;
	dec[n-1]=1;
	
	for(int i=1;i<n;i++)
	{
		inc[i]=(a[i]>a[i-1])? inc[i-1]+1:1;
	}
	
	for(int i=n-2;i>=0;i--)
	{
		dec[i]=(a[i]>a[i+1])? dec[i+1]+1:1;
	}
	
	int result=inc[0]+dec[0]-1;
	for(int i=1;i<n;i++)
	{
		if((inc[i]+dec[i]-1)>result)
		result=inc[i]+dec[i]-1;
	}
	return result;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		cout<<largest_bitonic(a,n)<<endl;
	}
}
