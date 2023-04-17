//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int check(string s,int l,int r)
    {
        while(l>=0 && r<s.length() && s[l]==s[r])
        l--,r++;
        return r-l-1;
    }
    string longestPalin (string S) 
    {
        int ans=0,st=0;
        for(int i=0;i<S.length();i++)
        {
            int l1=check(S,i,i);
            int l2=check(S,i,i+1);
            int l=max(l1,l2);
            if(l>ans)
            {
                ans=l;
                st=i-(l-1)/2;
            }
        }
        return S.substr(st,ans);
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends