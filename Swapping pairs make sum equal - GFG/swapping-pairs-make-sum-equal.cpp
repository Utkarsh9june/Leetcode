//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    private:
    bool binsearch(int b[],int n,int num)
    {
        int low=0,high=n-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(b[mid]==num) return 1;
            else if(b[mid]<num) low=mid+1;
            else high=mid-1;
        }
        return 0;
    }
	public:
	int findSwapValues(int a[], int n, int b[], int m)
	{
	    int sum1=0,sum2=0;
	    sort(a,a+n);
	    sort(b,b+m);
	    for(int i=0;i<n;i++)
	    {
	        sum1+=a[i];
	    }
	    for(int i=0;i<m;i++)
	    {
	        sum2+=b[i];
	    }
	    
	    if((sum1+sum2)%2) return -1;
	    int avg=(sum1+sum2)/2;
	    int diff=avg-min(sum1,sum2);
	    for(int i=0;i<n;i++)
	    {
	        if(binsearch(b,m,a[i]+diff)||binsearch(b,m,a[i]-diff)) return 1;
	    }
	    return -1;
	}
 

};

//{ Driver Code Starts.

int main() 
{
   	
   	int t;
    cin >> t;
    while (t--)
    {
    	int n,m;
        cin>>n>>m;
        int a[n];
        int b[m];
        for(int i=0;i<n;i++)
            cin>>a[i];
        for(int i=0;i<m;i++)
            cin>>b[i];
        

        Solution ob;
        cout <<  ob.findSwapValues(a, n, b, m);
	    cout << "\n";
	     
    }
    return 0;
}






// } Driver Code Ends