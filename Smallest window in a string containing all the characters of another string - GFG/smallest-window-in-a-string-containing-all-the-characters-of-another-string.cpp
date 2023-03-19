//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string p)
    {
        if(s.length()<p.length())
        return "-1";
        unordered_map<char,int> mp;
        int cnt=0;
        for(int i=0;i<p.length();i++)
        {
            if(!mp[p[i]])
            cnt++;
            mp[p[i]]++;
        }
        int i=0,j=0,len=INT_MAX,start=0;
        while(j<s.length())
        {
            mp[s[j]]--;
            if(mp[s[j]]==0) cnt--;
            if(cnt==0)
            {
                while(cnt==0)
                {
                    if(len>j-i+1)
                    {
                        len=min(len,j-i+1);
                        start=i;
                    }
                    mp[s[i]]++;
                    if(mp[s[i]]>0) cnt++;
                    i++;
                }
            }
            j++;
        }
        if(len!=INT_MAX) 
        return s.substr(start,len);
        return "-1";
    }
};

//{ Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends