//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int f(int ind,int amt,vector<int> &nums,vector<vector<int>> &dp)
	{
	    if(ind==0)
	    {
	        if(amt%nums[0]==0) return amt/nums[0];
	        return 1e9;
	    }
	    if(dp[ind][amt]!=-1) 
	    return dp[ind][amt];
	    
	    
	}
	int MinCoin(vector<int>nums, int t)
	{
	    int n=nums.size();
	    vector<vector<int>> dp(n,vector<int>(t+1,0));
	    for(int i=0;i<=t;i++)
	    {
	        if(i%nums[0]==0)
	        dp[0][i]=i/nums[0];
	        else
	        dp[0][i]=1e9;
	    }
	    for(int ind=1;ind<n;ind++)
	    {
	        for(int amt=0;amt<=t;amt++)
	        {
	            int nt=dp[ind-1][amt];
	            int t=INT_MAX;
	            if(nums[ind]<=amt)
	            t=1+dp[ind][amt-nums[ind]];
	    
	            dp[ind][amt] =min(nt,t);
	        }
	    }
	    
	    
	    int ans = dp[n-1][t];
	    if(ans>=1e9) return -1;
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, amount;
		cin >> n >> amount;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution ob;
		int ans = ob.MinCoin(nums, amount);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends