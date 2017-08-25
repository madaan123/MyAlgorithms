#include<bits/stdc++.h>
using namespace std;

// The cost of a stock on each day is given in an array, find the max profit that you can make by buying and selling in those days.
//	Example
//	2
//	7
//	100 180 260 310 40 535 695
//	Output:
//	(0 3) (4 6)
struct stock{
  int buy;
  int sell;
};

void funct(int a[],int n)
{
    stock s[n/2+1];
    int i=0;
    int count=0;
    while(i<n)
    {
        while(a[i]>=a[i+1] & i<n-1)			// finding a local minima
        i++;
        
        if(i==n-1)
        break;
        
        s[count].buy=i++;
        
        while(a[i]>=a[i-1] && i<n)			// finding a local maxima
        i++;
        
        s[count].sell=i-1;
        
        count++;
    }
    for(int i=0;i<count;i++)
    {
        cout<<"("<<s[i].buy<<" "<<s[i].sell<<") ";
    }
    if(count==0)
    cout<<"No Profit";
    cout<<endl;
}

int main()
 {
	int t;
        cin>>t;
       while(t--)
       {
               int n;
               cin>>n;
               int a[n];
               for(int i=0;i<n;i++)
               cin>>a[i];
               funct(a,n);
        }
	return 0;
}
