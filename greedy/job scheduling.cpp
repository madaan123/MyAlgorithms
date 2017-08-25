#include<bits/stdc++.h>
using namespace std;

struct job{
	char id;
	int dead;
	int profit;
};

bool compare_by_profit(job a1,job a2)
{
	return (a1.profit>a2.profit);
}

void job_scheduling(job arr[],int n)
{
	sort(arr,arr+n,compare_by_profit);
	int result[n];
	bool slot[n];
	
	for(int i=0;i<n;i++)
	slot[i]=false;
	
	for(int i=0;i<n;i++)
	{
		for(int j=min(n,arr[i].dead)-1;j>=0;j--)
		{
			if(slot[j]==false)
			{
				result[j]=i;
				slot[j]=true;
				break;
			}
		}
	}
	
	for(int i=0;i<n;i++)
	{
		if(slot[i])
		cout<<arr[result[i]].id<<" ";
	}
}

int main()
{
	int n;
	cin>>n;
	job arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i].id;
		cin>>arr[i].dead;
		cin>>arr[i].profit;
	}
	job_scheduling(arr,n);
}
