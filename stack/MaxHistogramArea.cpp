#include<bits/stdc++.h>
using namespace std;

int MaxArea(int a[],int n)
{
	stack<int>S; 
	int area;
	int maxArea=-1;
	int top,i;
	S.push(0);
	for(i=1;i<n;i++)
	{
		if(a[i]>=a[S.top()])
		{
			S.push(i);
		}
		else
		{
			while(!S.empty() && a[i]<a[S.top()])
			{
				top=S.top();
				S.pop();
				if(!S.empty())
				{
					area=a[top]*(i-S.top()-1);
				}
				else
				{
					area=i*a[top];
					//break;
				}
				if(area>maxArea)
				{
					maxArea=area;
				//	cout<<maxArea<<endl;
				}	
			}
			
			S.push(i);
		}
	}
	
	while(!S.empty())
	{
				top=S.top();
				S.pop();
				if(!S.empty())
				{
					area=a[top]*(i-S.top()-1);
				}
				else
				{
					area=i*a[top];
				}
				//cout<<area<<"";
				if(area>maxArea)
				{
					maxArea=area;
				}
	}
	return maxArea;
}

int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	cin>>a[i];
	cout<<MaxArea(a,n)<<endl;
}
