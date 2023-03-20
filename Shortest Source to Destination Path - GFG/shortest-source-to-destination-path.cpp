//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestDistance(int n, int m, vector<vector<int>> grid, int x, int y) 
    {
        queue<pair<int,pair<int,int>>> q;
        vector<vector<int>> dist(n,vector<int>(m,1e9));
        
        dist[0][0]=0;
        q.push({0,{0,0}});
        
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        
        if(!grid[0][0]) return -1;
        if(grid[x][y]==0) return -1;
        while(!q.empty())
        {
            auto it=q.front();
            q.pop();
            int dis=it.first;
            int r=it.second.first;
            int c=it.second.second;
            
            for(int i=0;i<4;i++)
            {
                int newr=r+dr[i];
                int newc=c+dc[i];
                if(newr>=0 && newr<n && newc>=0 && newc<m && grid[newr][newc] && dis+1<dist[newr][newc])
                {
                    dist[newr][newc]=dis+1;
                    if(newr==x && newc==y)
                    return dis+1;
                    q.push({dis+1,{newr,newc}});
                }
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
// } Driver Code Ends