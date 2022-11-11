class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int> dp(n+1,0);
        
        for(int i=2;i<=n;i++)
        {
            int onestep=cost[i-1]+dp[i-1];
            int twostep=cost[i-2]+dp[i-2];
            
            dp[i]=min(onestep,twostep);
        }
        return dp[n];
    }
};