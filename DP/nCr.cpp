// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:

    int dp[1001][1001];
    
    int bc(int n, int r)
    {
        if(r>n)
        {
            return 0;
        }
        if(dp[n][r] != -1)
        {
            return dp[n][r];
        }
        if(r==0 || r==n)
        {
            dp[n][r] = 1;
            return dp[n][r];
        }
        
        dp[n][r] = (bc(n-1,r-1) + bc(n-1,r)) % 1000000007;
        
        return dp[n][r];
    }
    
    int nCr(int n, int k)
    {
        for(int i=0;i<1001;i++)
        {
            for(int j=0;j<1001;j++)
            {
                dp[i][j] = -1;
            }
        }
        int ans = bc(n,k);
        return ans % 1000000007;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, r;
        cin>>n>>r;
        
        Solution ob;
        cout<<ob.nCr(n, r)<<endl;
    }
    return 0;
}  // } Driver Code Ends