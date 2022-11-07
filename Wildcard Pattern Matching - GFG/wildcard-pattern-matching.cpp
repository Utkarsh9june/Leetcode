//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
  public:
/*You are required to complete this method*/
    bool isAllStars(string & S1, int i) {
  for (int j = 0; j <= i; j++) {
    if (S1[j] != '*')
        return false;
        }
        return true;
    }
    int f(int i,int j,string s1,string s2,vector<vector<int>> &dp)
    {
        if(i==-1)
        {
            if(j==-1)
            return 1;
            return 0;
        }
  if (j < 0 && i >= 0)
    return isAllStars(s1, i);
        
        if(dp[i][j]!=-1)
        return dp[i][j];
        
        if(s1[i]==s2[j] || s1[i]=='?')
        return dp[i][j]=f(i-1,j-1,s1,s2,dp);
        else
        {
            if(s1[i]=='*')
            return f(i-1,j,s1,s2,dp)||f(i,j-1,s1,s2,dp);
            return 0;
        }
    }
    int wildCard(string pattern,string str)
    {
        int n=pattern.size(),m=str.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return f(n-1,m-1,pattern,str,dp);
    }
};

//{ Driver Code Starts.
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
           string pat,text;
           cin>>pat;
cin.ignore(numeric_limits<streamsize>::max(),'\n');
           cin>>text;
           Solution obj;
           cout<<obj.wildCard(pat,text)<<endl;
   }
}

// } Driver Code Ends