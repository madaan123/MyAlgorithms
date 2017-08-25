#include<bits/stdc++.h>
using namespace std;
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
               stack<int>S;
               int span[n];
               span[0]=1;
               S.push(0);
               int c;
               for(int i=1;i<n;i++)
               {
                   while(a[i]>=a[S.top()])
                   {
                       S.pop();
                       if(S.empty())
                       break;
                   }
                   span[i]=(S.empty())?(i+1):(i-S.top());
                   S.push(i);
               }
               for(int i=0;i<n;i++)
               cout<<span[i]<<" ";cout<<endl;
        }
	return 0;
}
