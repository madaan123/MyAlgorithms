#include<bits/stdc++.h>
using namespace std;

void swap(char *a,char *b)
{
    char temp=*a;
    *a=*b;
    *b=temp;
}

void print(char* s,int l,int r)
{
    if(l==r)
    cout<<s<<" ";
    
    else
    {
        for(int i=l;i<=r;i++)
        {
            swap(&s[l],&s[i]);
            print(s,l+1,r);
            swap(&s[l],&s[i]);          // backtrack
        }
    }
}

int main()
 {
               string s;
               cin>>s;
               int n=s.length();
               char str[n];
               for(int i=0;i<n;i++)
               str[i]=s[i];
               sort(str,str+n);
               print(str,0,n-1);
               cout<<endl;
	return 0;
}
