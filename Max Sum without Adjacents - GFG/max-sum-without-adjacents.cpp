//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	

    int f(int ind,int arr[],vector<int>&dp)
    {
        if(ind==0)
        return arr[0];
        if(ind<0)
        return 0;
        if(dp[ind]!=-1)
        return dp[ind];
        
        int pick=arr[ind]+f(ind-2,arr,dp);
        int notpick=f(ind-1,arr,dp);
        
        return dp[ind]=max(pick,notpick);
    }

	int findMaxSum(int *arr, int n) 
	{
	    vector<int> dp(n+1,-1);
	    dp[0]=arr[0];
	    for(int i=1;i<=n;i++)
	    {
	        int pick=arr[i];
	        if(i>1)
	        pick+=dp[i-2];
	        int npick=dp[i-1];
	        
	        dp[i]=max(pick,npick);
	    }
	    return dp[n-1];
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends