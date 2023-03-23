//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
private:
    bool ispossible(vector<int> a,int n,int k,int mid)
    {
        int cow=1,pos=a[0];
        for(int i=0;i<n;i++)
        {
            if(a[i]-pos>=mid)
            {
                pos=a[i];
                cow++;
            }
            if(cow==k)
            return true;
        }
        return false;
    }
public:
    int solve(int n, int k, vector<int> v) 
    {
        sort(v.begin(),v.end());
        int low=1,high=v[n-1]-v[0];
        int res=0;
        while(low<=high)
        {
            int mid=(low+high)>>1;
            if(ispossible(v,n,k,mid))
            {
                res=mid;
                low=mid+1;
            }
            else
            high=mid-1;
        }
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends