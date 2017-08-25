#include<bits/stdc++.h>
using namespace std;

void printNge(int a[],int n)
{
	stack<int> S;
	S.push(a[0]);
	int next,element;
	for(int i=1;i<n;i++)
	{
		next=a[i];
		if(!S.empty())
		{
			element=S.top();
			S.pop();
			while(element<next)
			{
				cout<<element<<" next greater is "<<next<<endl;
				if(S.empty())
				break;
				element=S.top();
				S.pop();
			}
			
			if(element>next)
			S.push(element);
		}
		S.push(next);
	}
	while(!S.empty())
	{
		cout<<S.top()<<" next greater is "<<-1<<endl;
		S.pop();
	}
}

int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	cin>>a[i];
	printNge(a,n);
}
