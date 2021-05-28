// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    int dp[1001][1001];
    int lcs(string a, string b, int n, int m)
    {
        if(n==0)
        {
            return m;
        }
        if(m==0)
        {
            return n;
        }
        if(dp[n][m] != -1)
        {
            return dp[n][m];
        }
        if(a[n-1] == b[m-1])
        {
            return dp[n][m] = lcs(a,b,n-1,m-1);
        }
        else
        {
            return dp[n][m] = 1 + min({lcs(a,b,n-1,m),lcs(a,b,n,m-1),lcs(a,b,n-1,m-1)});
        }
    }
    
    int editDistance(string s, string t) {
        int n = s.size();
        int m = t.size();
        for(int i=0;i<1001;i++)
        {
            for(int j=0;j<1001;j++)
            {
                dp[i][j] = -1;
            }
        }
        int ans = lcs(s,t,n,m);
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends