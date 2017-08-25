#include<iostream>
using namespace std;

// Find maximum sum so that no two elelments are adjacent
//	3 2 5 10 7 should return 15
//	3 2 7 10 should return 13

int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	cin>>a[i];
	
	int excl=0;
	int incl=a[0];
	int exclnew;
	for(int i=1;i<n;i++)
	{
		exclnew=max(excl,incl);
		incl=excl+a[i];
		excl=exclnew;
	}
	
	cout<<max(excl,incl)<<endl;                                                      
}
