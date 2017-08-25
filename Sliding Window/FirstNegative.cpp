#include<bits/stdc++.h>
using namespace std;

/*
Given an array and a positive integer k, find the first negative integer for each and every window(contiguous subarray) of size k.
Example:
Input:
2
5
-8 2 3 -6 10
2
8
12 -1 -7 8 -15 30 16 28
3

Output:
-8 0 -6 -6
-1 -1 -7 -15 -15 0
*/
int main()
 {
	int t;
        cin>>t;
       while(t--)
       {
               int n,k;
               cin>>n;
               int a[n];
               for(int i=0;i<n;i++)
               cin>>a[i];
               cin>>k;
               queue<int>Q;
               int flag=0;
               for(int i=0;i<k;i++)
               {
                   if(a[i]<0)
                   {
                       Q.push(i);
                   }
               }
               
               
               for(int i=k;i<n;i++)
               {
                   if(!Q.empty())
                   cout<<a[Q.front()]<<" ";
                   else
                   cout<<0<<" ";
                   
                   while(!Q.empty() && Q.front()<(i-k+1))
                   {
                       Q.pop();
                   }
                   
                   if(a[i]<0)
                   Q.push(i);
                   
               }
               if(!Q.empty())
                   cout<<a[Q.front()]<<" ";
                   else
                   cout<<0<<" ";
               cout<<endl;
        }
	return 0;
}
