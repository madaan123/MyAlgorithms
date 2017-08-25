#include<bits/stdc++.h>
using namespace std;

void print_result(char* result,int res_size)
{
	for(int i=0;i<res_size;i++)
	cout<<result[i];
	cout<<endl;
	return;
}

void printPermutations(char* str,int* count,char* result,int level,int res_size,int str_size)
{
	if(level==res_size)
	{
		print_result(result,res_size);
		return;
	}

	for(int i=0;i<str_size;i++)
	{
		if(count[i]==0)
		continue;
		
		result[level]=str[i];
		count[i]--;
		printPermutations(str,count,result,level+1,res_size,str_size);
		count[i]++;
	}
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
	cin>>s;
	map<char,int>mymap;
	for(int i=0;i<s.length();i++)
	{
		mymap[s[i]]++;
	}
	int index=0;
	int size=mymap.size();
	map<char,int>::iterator it;
	char *str=new char[size];
	int *count=new int[size];
	for(it=mymap.begin();it!=mymap.end();it++)
	{
		str[index]=it->first;
		count[index]=it->second;
		index++;
	}
	char *result=new char[s.length()];
	printPermutations(str,count,result,0,s.length(),size);
	}
}
