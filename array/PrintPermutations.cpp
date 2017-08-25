#include<bits/stdc++.h>
using namespace std;

void PrintPermutations(char* s,int l,int h)
{
	if(l==h)
	{
		cout<<s<<" ";
		sort(s+0,s+h);
	}
	
	else
	{
		for(int i=l;i<=h;i++)
		{
			swap(s[i],s[l]);
			PrintPermutations(s,l+1,h);
			//swap(s[i],s[l]);
		}
	}
}

int main()
{
	string s;
	cin>>s;
	int n;
	n=s.length();
	char str[n];
	for(int i=0;i<n;i++)
	str[i]=s[i];
	sort(str,str+n);
	PrintPermutations(str,0,s.length()-1);
	cout<<endl;
}
