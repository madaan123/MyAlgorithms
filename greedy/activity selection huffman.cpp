#include<bits/stdc++.h>
using namespace std;

struct activity{
	int start,end;
};

bool activity_compare(activity a1,activity a2)
{
	return (a1.end<a2.end);							// sort the activities according to the ending time of the activities
}

int printmaxactivity(activity arr[],int n)
{
	sort(arr,arr+n,activity_compare);
	cout<<"Following activities are selected"<<endl;
	int i=0;
	cout<<"("<<arr[i].start<<" , "<<arr[i].end<<" ) ";			// start from the first activity 
	
	int k=0;
	
	for(int j=1;j<n;j++)
	{
		if(arr[j].start>=arr[i].end)				// include those activities whose start time begins after previous activity ends
		{
			cout<<"("<<arr[j].start<<" , "<<arr[j].end<<" ) ";
			i=j;
		}
	}
}

int main()
{
	int n;
	cin>>n;
	activity arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i].start;
		cin>>arr[i].end;
	}
	
	printmaxactivity(arr,n);
	return 0;
}
