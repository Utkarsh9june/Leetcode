//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//Back-end complete function Template for C++

class Solution {
  public:
    int f(int ind,vector<int> &dp,vector<int> &cost)
    {
        if(ind==0||ind==1)
        return cost[ind];
        if(dp[ind]!=-1)
        return dp[ind];
        
        int one=cost[ind]+f(ind-1,dp,cost);
        int two=cost[ind]+f(ind-2,dp,cost);
        
        return dp[ind]=min(one,two);
    }
  
    int minCostClimbingStairs(vector<int>&cost ,int N) {
        vector<int> dp(N+1,0);
        
        for(int i=2;i<=N;i++)
        {
            int one=cost[i-1]+dp[i-1];
            int two=cost[i-2]+dp[i-2];
            
            dp[i]=min(one,two);
        }
        return dp[N];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        vector<int>cost(N);
        
        for(int i=0 ; i<N ; i++){
            cin>>cost[i];
        }

        Solution ob;
        cout<<ob.minCostClimbingStairs(cost,N);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends