//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class DisjointSet
{
    vector<int> size,parent;
    public:
    DisjointSet(int n)    {
        parent.resize(n+1);
        size.resize(n+1,1);
        for(int i=0;i<=n;i++)
        {
            parent[i]=i;
        }
    }
    int findUpar(int node)    {
        if(parent[node]==node)
        return node;
        return parent[node]=findUpar(parent[node]);
    }
    void unionBysize(int u,int v)    {
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
    vector<vector<string>> accountsMerge(vector<vector<string>>& details) {
        int n=details.size();
        DisjointSet ds(n);
        unordered_map<string,int> mapmailnode;
        for(int i=0;i<n;i++)
        {
            for(int j=1;j<details[i].size();j++)
            {
                string mail=details[i][j];
                if(mapmailnode.find(mail)==mapmailnode.end())
                mapmailnode[mail]=i;
                else
                ds.unionBysize(i,mapmailnode[mail]);
            }
        }
        
        vector<string> mergedmail[n];
        for(auto it:mapmailnode)
        {
            string mail=it.first;
            int node=ds.findUpar(it.second);
            mergedmail[node].push_back(mail);
        }
        
        vector<vector<string>> ans;
        for(int i=0;i<n;i++)
        {
            if(mergedmail[i].size()==0)
            continue;
            sort(mergedmail[i].begin(),mergedmail[i].end());
            vector<string> temp;
            temp.push_back(details[i][0]);
            for(auto it:mergedmail[i])
            {
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        return ans;
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
    vector<vector<string>> accounts;

    for (int i = 0; i < n; i++)
    {
      vector<string> temp;
      int x;
      cin >> x;

      for (int j = 0; j < x; j++)
      {
        string s1;
        cin >> s1;
        temp.push_back(s1);
      }
      accounts.push_back(temp);
    }

    Solution obj;
    vector<vector<string>> res = obj.accountsMerge(accounts);
    sort(res.begin(), res.end());
    cout << "[";
    for (int i = 0; i < res.size(); ++i)
    {
      cout << "[";
      for (int j = 0; j < res[i].size(); j++)
      {
        if (j != res[i].size() - 1)
          cout << res[i][j] << ","
               << " ";
        else
          cout << res[i][j];
      }
      if (i != res.size() - 1)
        cout << "], " << endl;
      else
        cout << "]";
    }
    cout << "]"
         << endl;
  }
}
// } Driver Code Ends