//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
private:
    void dfs(vector<vector<int>>& ans,vector<vector<int>>& img,
    int sr,int sc,int inicolor,int newcolor)
    {
        int n=img.size(),m=img[0].size();
        ans[sr][sc]=newcolor;
        int dr[]={-1,0,+1,0};
        int dc[]={0,+1,0,-1};
        for(int i=0;i<4;i++)
        {
            int nr=sr+dr[i];
            int nc=sc+dc[i];
            if(nr>=0 && nr<n && nc>=0 && nc<m && ans[nr][nc]==inicolor && ans[nr][nc]!=newcolor)
            dfs(ans,img,nr,nc,inicolor,newcolor);
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& img,
    int sr, int sc, int newcolor) {
        int inicolor=img[sr][sc];
        vector<vector<int>> ans=img;
        dfs(ans,img,sr,sc,inicolor,newcolor);
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends