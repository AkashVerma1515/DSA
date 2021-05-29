// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends



class Solution
{
    public:
    
    int dp[10001];
    int maxi(int n,int x,int y,int z)
    {
        if(n==0)
        {
            return 0;
        }
        if(dp[n] != -1)
        {
            return dp[n];
        }
        int a=INT_MIN,b=INT_MIN,c=INT_MIN;
        if(n>=x)
        {
            a = 1 + maxi(n-x,x,y,z);
        }
        if(n>=y)
        {
            b = 1 + maxi(n-y,x,y,z);
        }
        if(n>=z)
        {
            c = 1 + maxi(n-z,x,y,z);
        }
        return dp[n] = max({a,b,c});
    }
    
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        memset(dp,-1,sizeof(dp));
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