//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int minimumCost(vector<vector<int>>& flights, int n, int k) {
        vector<pair<int,int>> adj[n+1];
        for(auto it:flights)
        {
            adj[it[0]].push_back({it[1],it[2]});
        }
        queue<pair<int,int>> q;
        q.push({0,k});
        vector<int> dist(n+1,1e9);
        dist[k]=0;
        while(!q.empty())
        {
            auto i=q.front();
            q.pop();
            int node=i.second;
            int dis=i.first;
            for(auto it:adj[node])
            {
                int adjnode=it.first;
                int cost=it.second;
                if(dis+cost<dist[adjnode])
                {
                    dist[adjnode]=dis+cost;
                    q.push({dis+cost,adjnode});
                }
            }
        }
        int ans=INT_MIN;
        for(int i=1;i<=n;i++)
        {
            if(dist[i]==1e9)
            return -1;
            ans=max(ans,dist[i]);
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int size;
        cin >> size;
        vector<vector<int>> flights(size,vector<int>(3));
        for (int i = 0; i < size; i++) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            flights[i]=temp;
        }

        Solution ob;
        cout << ob.minimumCost(flights, n, k) << "\n";
    }
}

// } Driver Code Ends