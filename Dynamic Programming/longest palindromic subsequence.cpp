#include<bits/stdc++.h>
using namespace std;  

int lps(string X,int m)
{
	int L[m+1][m+1];
   int i, j;
  
   /* Following steps build L[m+1][n+1] in bottom up fashion. Note 
      that L[i][j] contains length of LCS of X[0..i-1] and Y[0..j-1] */
   for (i=0; i<=m; i++)
   {
     for (j=0; j<=m; j++)
     {
       if (i == 0 || j == 0)
         L[i][j] = 0;
  
       else if (X[i-1] == X[m-j])
         L[i][j] = L[i-1][j-1] + 1;
  
       else
         L[i][j] = max(L[i-1][j], L[i][j-1]);
     }
   }
   
   for(int i=0;i<=m;i++)
	{
		for(int j=0;j<=m;j++)
		{
			cout<<L[i][j]<<" ";
		}
		cout<<endl;
	}
	
	// subtract this length from the length of the string to find minimum number of deletions to convert into longest 
  	//  increasig subsequence
	cout<<L[m][m]<<endl;
}

int main()
{
  string X;			// longest common subsequece of a string and its reverse is its longest palindromic subsequence
  cin>>X;
  
  int m = X.length();
  
  lps(X,m);
 
  return 0;
}
