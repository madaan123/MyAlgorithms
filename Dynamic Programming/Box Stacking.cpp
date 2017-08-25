#include<bits/stdc++.h>
using namespace std;

struct Box{
	int heigth;
	int breadth;
	int length;
};

bool compare(Box a,Box b)
{
	int a1=a.breadth*a.length;
	int a2=b.length*b.breadth;
	return (a1>a2);
}

int MaxHeight(Box arr[],int n)
{
	Box box[3*n];
	int index=0;
	for(int i=0;i<n;i++)
	{
		box[index]=arr[i];
		index++;
		
		box[index].heigth=arr[i].breadth;
		box[index].length=max(arr[i].length,arr[i].heigth);
		box[index].breadth=min(arr[i].length,arr[i].heigth);
		index++;
		
		box[index].heigth=arr[i].length;
		box[index].length=max(arr[i].breadth,arr[i].heigth);
		box[index].breadth=min(arr[i].breadth,arr[i].heigth);
		index++;
		
	}
	
	n=3*n;
	sort(box,box+n,compare);
	for(int i=0;i<n;i++)
	{
		cout<<box[i].length<<" "<<box[i].breadth<<" "<<box[i].heigth<<endl;
	}
	
	int maxHeigth[n];
	for(int i=0;i<n;i++)
	{
		maxHeigth[i]=box[i].heigth;
	}
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<i;j++)
		{
			if(box[j].length>box[i].length && box[j].breadth>box[i].breadth && box[i].heigth+maxHeigth[j]>maxHeigth[i])
			{
				maxHeigth[i]=box[i].heigth+maxHeigth[j];
			}
		}
	}
	
	int max=-1;
	for(int i=0;i<n;i++)
	{
		if(maxHeigth[i]>max)
		max=maxHeigth[i];
	}
	return max;
}

int main()
{
	int n;
	cin>>n;
	Box arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i].length;
		cin>>arr[i].breadth;
		cin>>arr[i].heigth;
	}
	
	cout<<MaxHeight(arr,n);
}
