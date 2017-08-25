#include<bits/stdc++.h>
using namespace std;

/*
You have been given two strings and you have been given some wildcard characetrs in first string.
? represents only one character and * represents more than one character
so we have to match them taking care of the wildcards
ex:-
s1= a*b*c?d
s2= aKKbJJJcPd

so s1 is matched correctly with s2
*/

bool WildcardMatch(string s1,string s2,int l2)
{
	string pat="";
	bool isfirst=true;
	
	int index=0;
	for(int i=0;i<s1.length();i++)
	{
		if(s1[i]=='*')
		{
			if(isfirst)
			{
				pat.push_back(s1[i]);
				isfirst=false;
			}
		}
		else
		{
			pat.push_back(s1[i]);
				isfirst=true;
		}
	}
	
	int l1=pat.length();
	bool dp[l2+1][l1+1];
	memset(dp,false,sizeof(dp));
	
	dp[0][0]=true;
	(s1[0]=='*')?(dp[0][1]=true):(dp[0][1]=false);
	for(int i=1;i<=l2;i++)
	{
		dp[i][0]=false;
	}
	
	for(int i=1;i<=l2;i++)
	{
		for(int j=1;j<=l1;j++)
		{
			if(s2[i-1]==pat[j-1] || pat[j-1]=='?')
			{
				dp[i][j]=dp[i-1][j-1];
			}
			else if(pat[j-1]=='*')
			{
				dp[i][j]=dp[i-1][j] | dp[i][j-1];
			}
		}
	}
	
	/*
	for(int i=0;i<=l2;i++)								// 	uncomment to see the dp matrix that is formed
	{
		for(int j=0;j<=l1;j++)
		cout<<dp[i][j]<<" ";
		cout<<endl;
	}
	*/
	
	return dp[l2][l1];
}

int main()
{
	string s1,s2;
	cin>>s1>>s2;
	cout<<WildcardMatch(s1,s2,s2.length());
}
