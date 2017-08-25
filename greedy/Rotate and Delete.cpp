#include<bits/stdc++.h>
using namespace std;

void rotate(long int a[],int start,int end)
{
    int k=a[end-1];
     for(int i=end-1;i>0;i--)
    {
        a[i]=a[i-1];
    }
    a[0]=k;
}

void print(long int a[],int n)
{
    for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
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
               long int a[n];
               for(int i=0;i<n;i++)
               cin>>a[i];
               int k=1,size=n;
               int start=0;
               while(size>1)
               {
                   rotate(a,start,size);
                   
                   print(a,size);
                   
                   if(k<=size)
                   {
                       for(int i=size-k;i<size-1;i++)
                       {
                           a[i]=a[i+1];
                       }
                       k++;
                   }
                   else
                   {
                       for(int i=0;i<size-1;i++)
                       {
                           a[i]=a[i+1];
                       }
                   }
                   size--;
                   print(a,size);
               }
        }
	return 0;
}
