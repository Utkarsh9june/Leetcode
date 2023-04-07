//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string findLargest(int N, int S){
        int num=0;
        string s="";
        if(S==0&&N!=1) return "-1";
        while(N)
        {
            if(S>9){
                s+='9';
                S-=9;
            }
            else{
                s+=to_string(S);
                S-=S;
            }
            N--;
        }
        if(S==0) return s;
        return "-1";
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, S;
        cin>>N>>S;
        
        Solution ob;
        cout<<ob.findLargest(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends