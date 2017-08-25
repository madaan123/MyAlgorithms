#include<iostream>
using namespace std;

/*
given an array find the maximum difference between any 2 elements such that greater element occurs after first element

7 9 5 6 3 2
output-2
(7,9)
*/

int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	cin>>a[i];
	
	int max,min;
	max=a[0];
	min=a[0];
	int diff=0;
	for(int i=1;i<n;i++)
	{
		if(a[i]>max)
		{
			max=a[i];
		}
		if(a[i]<max)
		{
			min=a[i];
			max=a[i];
		}
		if(max-min>diff)
		diff=max-min;
	}
	cout<<diff<<endl;
}
