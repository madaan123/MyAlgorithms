#include<bits/stdc++.h>
using namespace std;
int main()
 {
	int t;
        cin>>t;
       while(t--)
       {
            int n,m;
            cin>>n>>m;
            char s1[n],s2[m];
            for(int i=0;i<n;i++)
            cin>>s1[i];
            for(int i=0;i<m;i++)
            cin>>s2[i];
            
            int count1[26]={0},count2[26]={0};
            for(int i=0;i<n;i++)
            count1[s1[i]-'a']++;
            for(int i=0;i<m;i++)
            count2[s2[i]-'a']++;
            
            string res;
            for(int i=0;i<26;i++)
            {
            	for(int j=0;j<min(count1[i],count2[i]);j++)
            	res.push_back('a'+i);
			}
			if(res=="")
			cout<<endl;
			cout<<res<<endl;
        }
	return 0;
}
