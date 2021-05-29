// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends



class Solution
{
    public:
    
    int maxi(int n,int x,int y,int z)
    {
        int dp[n+1];
        dp[0] = 0;
        int a= INT_MIN,b=INT_MIN,c=INT_MIN;
        for(int i=1;i<n+1;i++)
        {
            if(i>=x)
            {
                a = 1 + dp[i-x];
            }
            if(i>=y)
            {
                b = 1 + dp[i-y];
            }
            if(i>=z)
            {
                c = 1 + dp[i-z];
            }
            dp[i] = max({a,b,c});
        }
        return dp[n];
    }
    
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        // memset(dp,-1,sizeof(dp));
        int ans = maxi(n,x,y,z);
        if(ans<0)
        {
            return 0;
        }
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}  // } Driver Code Ends