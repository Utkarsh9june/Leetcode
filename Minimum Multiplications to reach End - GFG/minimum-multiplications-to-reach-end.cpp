//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int s, int e) 
    {
        queue<pair<int,int>> q;
        q.push({0,s});
        int mod=100000;
        vector<int> dist(mod,1e9);
        dist[s]=0;
        while(!q.empty())
        {
            auto i=q.front();
            q.pop();
            int node=i.second;
            int steps=i.first;
            for(auto it:arr)
            {
                int num=(it*node)%mod;
                if(steps+1<dist[num])
                {
                    if(num==e)
                    return steps+1;
                    dist[num]=steps+1;
                    q.push({steps+1,num});
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
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends