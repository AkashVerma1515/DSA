// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int longestSubsequence(int n, int a[])
    {
        int dp[n];
        for(int i=0;i<n;i++)
        {
            dp[i] = 1;          // if there is only one element ,answer would be one.
        }
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(a[i] == a[j] + 1 || a[i] == a[j] - 1)
                {
                    dp[i] = max(dp[i],dp[j]+1);
                }
            }
        }
        return *max_element(dp,dp+n);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int A[N];
        for(int i = 0;i < N;i++)
            cin>>A[i];
        
        Solution ob;
        cout<<ob.longestSubsequence(N, A)<<endl;
    }
    return 0;
}  // } Driver Code Ends