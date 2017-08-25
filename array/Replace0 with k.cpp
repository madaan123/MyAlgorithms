#include<iostream>
using namespace std;

int Replace0(int n,int m)
{
	if(n==0)
	return 0;
	
	int k=n%10;
	if(k==0)
	k=m;
	
	return k+Replace0(n/10,m)*10;
}

int main()
{
	int n,m;
	cin>>n>>m;
	cout<<Replace0(n,m);
}
