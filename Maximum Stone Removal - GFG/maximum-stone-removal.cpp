//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class DisjointSet
{
    vector<int> size,parent;
    
    public:
    DisjointSet(int n)
    {
        parent.resize(n+1);
        size.resize(n+1,1);
        for(int i=0;i<=n;i++)
        {
            parent[i]=i;
        }
    }
    
    int findUpar(int node)
    {
        if(parent[node]==node)
        return node;
        return parent[node]=findUpar(parent[node]);
    }
    
    void unionBysize(int u,int v)
    {
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
    int maxRemove(vector<vector<int>>& stones, int n) {
        int maxr=0,maxc=0;
        for(auto it:stones)
        {
            maxr=max(it[0],maxr);
            maxc=max(it[1],maxc);
        }
        DisjointSet ds(maxr+maxc+1);
        unordered_map<int,int> nodes;
        for(auto it:stones)
        {
            int noder=it[0];
            int nodec=it[1]+maxr+1;
            ds.unionBysize(noder,nodec);
            nodes[noder]=1;
            nodes[nodec]=1;
        }
        int cnt=0;
        for(auto it:nodes)
        {
            if(ds.findUpar(it.first)==it.first)
            cnt++;
        }
        return n-cnt;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> adj;

        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int i = 0; i < 2; ++i) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;

        cout << obj.maxRemove(adj, n) << "\n";
    }
}
// } Driver Code Ends