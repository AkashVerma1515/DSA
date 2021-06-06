class Solution {
public:
    
    int dp[101][101];
    
    int count(int i, int j, int m, int n)
    {
        if(i==m-1 && j==n-1)
        {
            return 1;
        }
        if(i>=m || j>=n)
        {
            return 0;
        }
        if(dp[i][j] != -1)
        {
            return dp[i][j];
        }
        return dp[i][j] = count(i+1,j,m,n) + count(i,j+1,m,n);
    }
    
    int uniquePaths(int m, int n) {
        memset(dp,-1,sizeof(dp));
        int ans = count(0,0,m,n);
        return ans;
    }
};