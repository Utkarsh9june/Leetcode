//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    vector<vector<int>> overlappedInterval(vector<vector<int>>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> v;
        v.push_back({nums[0][0],nums[0][1]});
        for(int i=1;i<n;i++)
        {
            int m=v.size();
            int start1=v[m-1][0],end1=v[m-1][1];
            int start2=nums[i][0],end2=nums[i][1];
            if(end1>=start2)
            {
                v.pop_back();
                end1=max(end1,end2);
                v.push_back({start1,end1});
            }
            else
            v.push_back({start2,end2});
        }
        return v;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>Intervals(n);
		for(int i = 0; i < n; i++){
			int x, y;
			cin >> x >> y;
			Intervals[i].push_back(x);
			Intervals[i].push_back(y);
		}
		Solution obj;
		vector<vector<int>> ans = obj.overlappedInterval(Intervals);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
		}
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends