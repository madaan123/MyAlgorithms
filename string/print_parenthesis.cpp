#include<iostream>
using namespace std;

void printparenthesis(int n,int i,int brackets,char *output)
{
	if(i==n+n)
	{
		output[i]='\0';
		if(brackets==0)
		cout<<output<<endl;
		return;
	}
	if(brackets<=n-(i/2))
	{
		output[i]='(';
		printparenthesis(n,i+1,brackets+1,output);
	}
	if(brackets)
	{
		output[i]=')';
		printparenthesis(n,i+1,brackets-1,output);
	}
}

int main()
{
	int n;
	cin>>n;
	char output[2*n];
	printparenthesis(n,0,0,output);
}
