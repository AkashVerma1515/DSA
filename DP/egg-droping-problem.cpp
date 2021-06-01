// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int dp[201][201];
    
    int egg(int e, int f)
    {
        if(f==0 || f==1)
        {
            return f;
        }
        if(e==1)
        {
            return f;
        }
        if(dp[e][f] != -1)
        {
            return dp[e][f];
        }
        int mini = INT_MAX, temp;
        for(int k = 1 ; k <= f ; k++)
        {
            temp = 1 + max(egg(e-1,k-1) , egg(e,f-k));
            mini = min(mini,temp);
        }
        return dp[e][f] = mini;
    }
    
    int eggDrop(int n, int k) 
    {
        memset(dp,-1,sizeof(dp));
        int ans = egg(n,k);
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;
        Solution ob;
        //calling function eggDrop()
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}
  // } Driver Code Ends