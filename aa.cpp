#include<bits/stdc++.h>
using namespace std;
int main()
 {
	int t;
        cin>>t;
       while(t--)
       {
            string s;
            cin>>s;
            string res;
            for(int i=0;i<s.length();i++)
            {
                if(i>0 && s[i]=='c')
                {
                    if(s[i-1]!='a')
                    res.push_back(s[i]);
                }
                
                else if(i<s.length() && s[i]=='a')
                {
                	if(s[i+1]!='c')
                	res.push_back(s[i]);
				}
                
                else if(s[i]!='b')
                {
                    res.push_back(s[i]);
                }
                
                //cout<<res<<endl;
            }
            cout<<res<<endl;
        }
	return 0;
}
