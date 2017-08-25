#include<bits/stdc++.h>
using namespace std;

/*
a program to remove all adjacent same characters in a string in the order of occurence of characters 
ex:-
input - dfaaafg
output - dg

dfaaafg-> dffg -> dg
*/

string removeChar(string s)
{
	int k,l,i,j=0;
	k=0;
	while(k!=1)
	{
		string s2;
		l=0;
		for(i=0;i<s.length()-1;i++)
		{
			if(s[i]==s[i+1])
			{
				l=1;
				for(j=i;j<s.length();j++)
				{
					if(s[j]!=s[i])
					break;
				}
				i=j-1;
			}
			else
			{
				s2.push_back(s[i]);
			}
		}
		if(s[s.length()-1]!=s[s.length()-2])
		s2.push_back(s[s.length()-1]);
		if(l==0)
		{
			k=1;
		}
		else
		{
			cout<<s2<<endl;
			s=s2;
			if(s2=="")
			break;
		}
	}
	
	return s;
}

int main()
 {
	string s;
	getline(cin,s);
	
	cout<<removeChar(s);
	return 0;
}
