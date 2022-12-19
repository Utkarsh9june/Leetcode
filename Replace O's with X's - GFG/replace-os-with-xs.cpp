//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    void dfs(int r,int c,vector<vector<int>>&vis,vector<vector<char>> mat)
    {
        vis[r][c]=1;
        int n=mat.size(),m=mat[0].size();
        int dr[]={-1,0,1,0};
        int dc[]={0,+1,0,-1};
        for(int i=0;i<4;i++)
        {
            int nr=r+dr[i];
            int nc=c+dc[i];
            if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc] && mat[nr][nc]=='O')
            dfs(nr,nc,vis,mat);
        }
    }
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        vector<vector<int>> vis(n,vector<int>(m,0));
        vector<vector<char>> ans(n,vector<char>(m,'X'));
        for(int i=0;i<n;i++)
        {
            if(mat[i][0]=='O' && !vis[i][0])
            dfs(i,0,vis,mat);
        }
        for(int i=0;i<n;i++)
        {
            if(mat[i][m-1]=='O' && !vis[i][m-1])
            dfs(i,m-1,vis,mat);
        }
        for(int j=0;j<m;j++)
        {
            if(mat[0][j]=='O' && !vis[0][j])
            dfs(0,j,vis,mat);
        }
        for(int j=0;j<m;j++)
        {
            if(mat[n-1][j]=='O' && !vis[n-1][j])
            dfs(n-1,j,vis,mat);
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(vis[i][j])
                ans[i][j]='O';
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends