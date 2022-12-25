//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  private:
    void dfs(int r,int c,vector<pair<int,int>> &v,vector<vector<int>> &grid,
            vector<vector<int>> &vis,int r0,int c0)
    {
        int n=grid.size(),m=grid[0].size();
        vis[r][c]=1;
        
        int x=r-r0,y=c-c0;
        v.push_back({x,y});
        
        int dr[]={-1,0,+1,0};
        int dc[]={0,+1,0,-1};
        
        for(int i=0;i<4;i++)
        {
            int nr=r+dr[i];
            int nc=c+dc[i];
            
            if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc] && grid[nr][nc])
            dfs(nr,nc,v,grid,vis,r0,c0);
        }
    }
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        set<vector<pair<int,int>>> st;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                vector<pair<int,int>> v;
                if(!vis[i][j]&&grid[i][j])
                {
                    dfs(i,j,v,grid,vis,i,j);
                    st.insert(v);
                }
            }
        }
        return st.size();
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends