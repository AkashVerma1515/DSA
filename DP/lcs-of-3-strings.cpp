// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int LCSof3 (string A, string B, string C, int n1, int n2, int n3);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n1, n2, n3; cin >> n1 >> n2 >> n3;
        string A, B, C; cin >> A >> B >> C;
        cout << LCSof3 (A, B, C, n1, n2, n3) << endl;
    }
}
// Contributed By: Pranay Bansal
// } Driver Code Ends

// 11 11 7
// ffmznimkkas vwsrenzkycx fxtlsgy

int LCSof3 (string A, string B, string C, int m, int n, int o)
{
    int dp[m+1][n+1][o+1];
    for(int i=0;i<m+1;i++)
    {
        for(int j=0;j<n+1;j++)
        {
            for(int k=0;k<o+1;k++)
            {
                if(i==0 || j==0 || k==0)
                {
                    dp[i][j][k] = 0;
                }
                else if(A[i-1] == B[j-1] && A[i-1] == C[k-1])
                {
                    dp[i][j][k] = 1 + dp[i-1][j-1][k-1];
                }
                else
                {
                    dp[i][j][k] = max({dp[i-1][j][k] , dp[i][j-1][k] , dp[i][j][k-1]});
                }
            }
        }
    }
    return dp[m][n][o];
}