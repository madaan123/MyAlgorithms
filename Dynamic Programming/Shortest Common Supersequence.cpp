#include<bits/stdc++.h>
using namespace std;  

/*
Given two strings str1 and str2, find the shortest string that has both str1 and str2 as subsequences.

Examples:

Input:   str1 = "geek",  str2 = "eke"
Output: "geeke"

Input:   str1 = "AGGTAB",  str2 = "GXTXAYB"
Output:  "AGXGTXAYB"
*/

int lcs(string X,string Y,int m,int n)
{
	int L[m+1][n+1];
   int i, j;
  
   /* Following steps build L[m+1][n+1] in bottom up fashion. Note 
      that L[i][j] contains length of LCS of X[0..i-1] and Y[0..j-1] */
   for (i=0; i<=m; i++)
   {
     for (j=0; j<=n; j++)
     {
       if (i == 0 || j == 0)
         L[i][j] = 0;
  
       else if (X[i-1] == Y[j-1])
         L[i][j] = L[i-1][j-1] + 1;
  
       else
         L[i][j] = max(L[i-1][j], L[i][j-1]);
     }
   }
   
	return L[m][n];
}

int main()
{
  int t;
  cin>>t;
  while(t--)
  {
      string X,Y;
      cin>>X>>Y;
      
      int m = X.length();
      int n = Y.length();
      
      int k=lcs(X,Y,m,n);
      int ans=m+n-k;
      cout<<ans<<endl;
  }
 
  return 0;
}
