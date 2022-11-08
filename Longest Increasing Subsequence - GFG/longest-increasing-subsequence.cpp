//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    int f(int ind,int prev,int n,int arr[],vector<vector<int>> &dp)
    {
        if(ind==n)
        return 0;
        
        if(dp[ind][prev+1]!=-1)
        return dp[ind][prev+1];
        
        int nt=f(ind+1,prev,n,arr,dp);
        int t=0;
        if(prev==-1||arr[ind]>arr[prev])
        t=1+f(ind+1,ind,n,arr,dp);
        
        return dp[ind][prev+1]=max(t,nt);
    }
    int longestSubsequence(int n, int a[])
    {
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return f(0,-1,n,a,dp);
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}

// } Driver Code Ends