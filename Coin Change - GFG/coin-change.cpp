//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long int f(int ind,int sum,int arr[],vector<vector<long long>> &dp)
    {
        if(ind==0)
        {
            if(sum%arr[ind]==0)
            return 1;
            return 0;
        }
        if(sum==0)
        return 1;
        
        if(dp[ind][sum]!=-1)
        return dp[ind][sum];
        
        long long int nottake=f(ind-1,sum,arr,dp);
        long long int take=0;
        if(arr[ind]<=sum)
        take=f(ind,sum-arr[ind],arr,dp);
        
        return dp[ind][sum]=take+nottake;
    }
    long long int count(int coins[], int N, int sum) {
        vector<vector<long long>> dp(N,vector<long long>(sum+1,-1));
        return f(N-1,sum,coins,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends