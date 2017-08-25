#include<iostream>
using namespace std;

int maxAmount(int low[],int high[],int n)
{
	int prepre=0;
	int pre=max(low[0],high[0]);
	int curr;
	for(int i=1;i<n;i++)
	{
		curr=max(high[i]+prepre,low[i]+pre);
		
		prepre=pre;
		pre=curr;
	}
	return curr;
}

int main()
{
	int n;
	cin>>n;
	int lowEffort[n];
	int highEffort[n];
	cout<<"Enter low and high tasks for your inputs"<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>lowEffort[i]>>highEffort[i];
	}
	cout<<maxAmount(lowEffort,highEffort,n);
}
