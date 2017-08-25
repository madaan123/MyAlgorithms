#include<bits/stdc++.h>
using namespace std;

bool sort_by_finish(pair<int,int> l,pair<int,int> r)
{
	return (l.second<r.second);
}

int main()
{
	int n;
	cin>>n;
	vector< pair<int,int> > v;
	int a[n],b[n];
	for(int i=0;i<n;i++)
	cin>>a[i];
	for(int i=0;i<n;i++)
	{
		cin>>b[i];
		v.push_back(make_pair(a[i],b[i]));
	}
	sort(v.begin(),v.end(),sort_by_finish);

}
