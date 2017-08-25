/*
Given two array A1[] and A2[], sort A1 in such a way that the relative order among the elements will be same as those  in A2. 
For the elements not present in A2. Append them at last in sorted order. 
It is also given that the number of elements in A2[] are smaller than or equal to number of elements in A1[] and A2[] has all distinct elements.

Input: A1[] = {2, 1, 2, 5, 7, 1, 9, 3, 6, 8, 8}
       A2[] = {2, 1, 8, 3}
Output: A1[] = {2, 2, 1, 1, 8, 8, 3, 5, 6, 7, 9}
*/

#include<bits/stdc++.h>
using namespace std;

int firstindex(int a[],int n,int x)
{
    int low=0;
    int high=n-1;
    int mid;
    int result=-1;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(a[mid]==x)
        {
            result=mid;
            high=mid-1;
        }
        else if(a[mid]>x)
        high=mid-1;
        else
        low=mid+1;
    }
    return result;
}

int main()
 {
	int t;
        cin>>t;
       while(t--)
       {
               int n,m;
               cin>>n>>m;
               int a[n],b[m];
               int temp[n],hash[n]={0};
               for(int i=0;i<n;i++)
               {
                   cin>>a[i];
                   temp[i]=a[i];
               }
               for(int i=0;i<m;i++)
               cin>>b[i];
               sort(temp,temp+n);
               int count=0;
               for(int i=0;i<m;i++)
               {
                   int f=firstindex(temp,n,b[i]);
                   if(f!=-1)
                   {
                       for(int j=f;j<n;j++)
                       {
                           if(temp[j]==b[i])
                           {
                               a[count++]=b[i];
                               hash[j]=1;
                           }
                       }
                   }
               }
               for(int i=0;i<n;i++)
               {
                   if(hash[i]==0)
                   a[count++]=temp[i];
               }
               for(int i=0;i<n;i++)
               cout<<a[i]<<" ";cout<<endl;
        }
	return 0;
}
