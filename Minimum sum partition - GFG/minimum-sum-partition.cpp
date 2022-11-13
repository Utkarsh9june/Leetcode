//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
	int minDifference(int arr[], int n)  { 
	    int totsum=0;
	    for(int i=0;i<n;i++) totsum+=arr[i];
	    
	    vector<vector<int>> dp(n,vector<int>(totsum+1,0));
	    
	    for(int i=0;i<n;i++) dp[i][0]=1;
	    dp[0][arr[0]]=1;
	    
	    for(int i=1;i<n;i++)
	    {
	        for(int tar=1;tar<=totsum;tar++)
	        {
	            bool nt=dp[i-1][tar];
	            bool t=0;
	            if(arr[i]<=tar)
	            t=dp[i-1][tar-arr[i]];
	            
	            dp[i][tar]=t||nt;
	        }
	    }
	    
	    int mini=INT_MAX;
	    for(int i=0;i<=totsum;i++)
	    {
	        if(dp[n-1][i]==1)
	        {
	            mini=min(mini,abs(i-(totsum-i)));
	        }
	    }
	    return mini;
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends