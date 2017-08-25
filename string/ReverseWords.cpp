#include<bits/stdc++.h>
using namespace std;

/*
Let the input string be “i like this program very much”. 
The function should change the string to “much very program this like i”

Input  : s = "geeks quiz practice code"
Output : s = "code practice quiz geeks"

Input  : s = "getting good at coding needs a lot of practice"
Output : s = "practice of lot a needs coding at good getting"
*/

void reverse_string(char *begin,char* end)
{
	int temp;
	while(begin<end)
	{
		temp=*begin;
		*begin=*end;
		*end=temp;
		begin++;
		end--;
	}
}

int main()
 {
	string s;
	getline(cin,s);
	int i=0,j;
	int prev=0;
	int n=s.length();
	while(i<s.length() && s[i]!=' ')
	{
		i++;
		if(s[i]==' ')
		{
			break;
		}
	}
	reverse_string(&s[prev],&s[i-1]);
	//cout<<prev<<" "<<i-1<<endl;
	prev=i+1;
	for(j=i+1;j<n;j++)
	{
		if(j<n && s[j]==' ')
		{
			//cout<<prev<<" "<<j-1<<endl;
			reverse_string(&s[prev],&s[j-1]);
			prev=j+1;
			
		}
		else if(j==n-1)
		{
			//cout<<prev<<" "<<j<<endl;
			reverse_string(&s[prev],&s[j]);
		}
	}
	reverse_string(&s[0],&s[n-1]);
	cout<<s<<endl;
	return 0;
}
