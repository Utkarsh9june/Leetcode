//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//Back-end complete function Template for C++

class Solution {
  public:
    int f(int ind,int tar,vector<int> &A,vector<vector<int>> &dp)
    {
        if(ind==0)
        {
            if(tar==0 && A[0]==0) return 2;
            if(tar==0 || A[0]==tar) return 1;
            return 0;
        }
        
        if(dp[ind][tar]!=-1)
        return dp[ind][tar];
        
        int nt=f(ind-1,tar,A,dp);
        int t=0;
        if(A[ind]<=tar)
        t=f(ind-1,tar-A[ind],A,dp);
        
        return dp[ind][tar]=t+nt;
    }
    int findTargetSumWays(vector<int>&A ,int target) {
        int n=A.size();
        int totsum=0;
        
        for(auto i : A) totsum+=i;
        
        int s2=(totsum-target)/2;
        
        if((totsum-target)%2) return 0;
        if(s2<0) return 0;
        
        vector<vector<int>> dp(n+1,vector<int>(s2+1,-1));
        
        return f(n-1,s2,A,dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        vector<int>arr(N);
        
        for(int i=0 ; i<N ; i++){
            cin>>arr[i];
        }
        int target;
        cin >> target;

        Solution ob;
        cout<<ob.findTargetSumWays(arr,target);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends