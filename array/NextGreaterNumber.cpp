#include <bits/stdc++.h>
using namespace std;
// A number is given in the form of a string and we have to find next gretaer number containing the same digits as the previous number
// input-143 output-341
int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    string s;
	    cin>>s;
	    int n=s.length();
	    char str[n];
	    for(int i=0;i<n;i++)
	    str[i]=s[i];
	    int i;
	    for(i=n-1;i>0;i--)
	    {
	        if(str[i]>str[i-1])
	        break;
	    }
	    if(i!=0)
	    {
	        int min=i;
	        int diff=INT_MAX;
	        for(int j=i+1;j<n;j++)
	        {
	            if(str[j]>str[i-1] && str[j]<str[i])
	            {
	                min=j;
	            }
	        }
	        swap(str[i-1],str[min]);
	        sort(str+i,str+n);
	        for(int i=0;i<n;i++)
	        cout<<str[i];cout<<endl;
	    }
	    else
	    {
	        cout<<"not possible"<<endl;
	    }
	}
	return 0;
}
