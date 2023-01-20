//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class DisjointSet
{
    public:
    vector<int> size,parent;
    public:
    DisjointSet(int n){
        parent.resize(n+1);
        size.resize(n+1,1);
        for(int i=0;i<=n;i++)
        {
            parent[i]=i;
        }
    }
    int findUpar(int node){
        if(parent[node]==node)
        return node;
        return parent[node]=findUpar(parent[node]);
    }
    void unionBysize(int u,int v){
        int a=findUpar(u);
        int b=findUpar(v);
        if(a==b)
        return;
        if(size[a]<size[b])
        {
            parent[a]=b;
            size[b]+=size[a];
        }
        else
        {
            parent[b]=a;
            size[a]+=size[b];
        }
    }
};
class Solution {
  public:
    int Solve(int n, vector<vector<int>>& edge) {
        DisjointSet ds(n);
        int extra=0;
        for(auto it:edge)
        {
            int u=it[0],v=it[1];
            if(ds.findUpar(u)==ds.findUpar(v))
            extra++;
            else
            ds.unionBysize(u,v);
        }
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(ds.parent[i]==i)
            cnt++;
        }
        int ans=cnt-1;
        if(extra>=ans)
        return ans;
        return -1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 2; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution Obj;
        cout << Obj.Solve(n, adj) << "\n";
    }
    return 0;
}
// } Driver Code Ends