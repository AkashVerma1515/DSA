// { Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int dp[501][501];
    
    bool isPalindrome(string s, int i, int j)
    {
        if(i==j)
        {
            return true;
        }
        if(i>j)
        {
            return false;
        }
        while(i<j)
        {
            if(s[i] != s[j])
            {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    
    int palindrome(string s, int i, int j)
    {
        if(i>=j)
        {
            return 0; 
        }
        if(dp[i][j] != -1)
        {
            return dp[i][j];
        }
        if(isPalindrome(s,i,j))
        {
            return 0;
        }
        int temp , mini = INT_MAX, left, right;
        for(int k=i ; k<=j-1 ; k++)
        {
            if(dp[i][k] != -1)
            {
                left = dp[i][k];
            }
            else
            {
                left = palindrome(s,i,k);
                dp[i][k] = left;
            }
            if(dp[k+1][j] != -1)
            {
                right = dp[k+1][j];
            }
            else
            {
                right = palindrome(s,k+1,j);
                dp[k+1][j] = right;
            }
            temp = left + right + 1;
            mini = min(temp,mini);
        }
        dp[i][j] = mini;
        return mini;
    }
    
    int palindromicPartition(string str)
    {
        memset(dp,-1,sizeof(dp));
        int ans = palindrome(str,0,str.size()-1);
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}  // } Driver Code Ends