//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool f(int ind,int sum,vector<int> arr,vector<vector<int>> dp)
    {
        if(sum==0)
        return 1;
        if(ind==0)
        return (arr[0]==sum);
        
        if(dp[ind][sum]!=-1)
        return dp[ind][sum];
        
        bool nt=f(ind-1,sum,arr,dp);
        bool t=0;
        if(arr[ind]<=sum)
        t=f(ind-1,sum-arr[ind],arr,dp);
        
        return t|nt;
    }
    bool isSubsetSum(vector<int>arr, int sum){
        int n=arr.size();
        vector<vector<int>> dp(n,vector<int>(sum+1,0));
        for(int i=0;i<n;i++)
        {
            dp[i][0]=1;
        }
        dp[0][arr[0]]=1;
        for(int ind=1;ind<n;ind++)
        {
            for(int tar=1;tar<sum+1;tar++)
            {
                bool nt=dp[ind-1][tar];
                bool t=0;
                if(arr[ind]<=tar)
                t=dp[ind-1][tar-arr[ind]];
                
                dp[ind][tar]=t|nt;
            }
        }
        return dp[n-1][sum];
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends