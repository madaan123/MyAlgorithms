#include<iostream>
using namespace std;

int maxsum(int a[],int b[],int c[],int n1,int n2,int n3)
{
	int sum1=0,sum2=0,sum3=0;
	for(int i=0;i<n1;i++)
	sum1+=a[i];
	for(int i=0;i<n2;i++)
	sum2+=b[i];
	for(int i=0;i<n3;i++)
	sum3+=c[i];
	int top1=0,top2=0,top3=0;
	int result;
	 while(1)
	 {
	 	if(top1==n1 || top2==n2 || top3==n3)
	 	return 0;
	 	
	 	if(sum1==sum2 && sum2==sum3)
	 	return sum1;
	 	
	 	if(sum1>=sum2 && sum1>=sum3)
	 	sum1-=a[top1++];
	 	if(sum2>=sum1 && sum2>=sum3)
	 	sum2-=b[top2++];
	 	if(sum3>=sum2 && sum3>=sum1)
	 	sum3-=a[top3++];
	 }
}

int main()
{
	int n1,n2,n3;
	cin>>n1>>n2>>n3;
	int a[n1],b[n2],c[n3];
	for(int i=n1-1;i>=0;i--)
	cin>>a[i];
	for(int i=n2-1;i>=0;i--)
	cin>>b[i];
	for(int i=n3-1;i>=0;i--)
	cin>>c[i];
	
}
