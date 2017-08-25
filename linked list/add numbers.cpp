#include <bits/stdc++.h>
using namespace std;

void addnumbers(int *a,int *b,int n1,int n2)
{
    int l=max(n1,n2);
    int res[l+1];
    int k;
    int s=0;
    if(n1>=n2)
    {
    	int m=n1-1,n=n2-1;
        for(int i=n1-1;i>=n1-n2;i--)
        {
        	s=s+a[m--]+b[n--];
        	res[i+1]=s%10;
        	s=s/10;
		}
		for(int i=n1-n2-1;i>=0;i--)
		{
			s=s+a[i];
			res[i+1]=s%10;
			s=s/10;
		}
    }
    else if(n1<n2)
    {
        int m=n1-1,n=n2-1;
        for(int i=n2-1;i>=n2-n1;i--)
        {
        	s=s+a[m--]+b[n--];
        	res[i+1]=s%10;
        	s=s/10;
		}
		for(int i=n2-n1-1;i>=0;i--)
		{
			s=s+b[i];
			res[i+1]=s%10;
			s=s/10;
		}
    }
    if(s)
    {
    	cout<<1<<" ";
	}
    for(int i=1;i<l+1;i++)
    {
    	cout<<res[i]<<" ";
	}
    cout<<endl;
}

int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n1,n2;
	    cin>>n1>>n2;
	    int a[n1],b[n2];
	    for(int i=0;i<n1;i++)
	    cin>>a[i];
	    for(int i=0;i<n2;i++)
	    cin>>b[i];
	    int carry=0;
	    int sum;
	    
	    addnumbers(a,b,n1,n2);
	}
	return 0;
}
