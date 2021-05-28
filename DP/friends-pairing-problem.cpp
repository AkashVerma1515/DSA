// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
    long long m = 1e9+7;
    int countFriendsPairings(int n) 
    { 
        int dp[n+1];
        for(int i=0;i<=n;i++)
        {
            if(i<=2)
            {
                dp[i] = i;
            }
            else
            {
                dp[i] = ((dp[i-1])%m + ((i-1)%m)*dp[i-2]%m) % m ;
            }
        }
        return dp[n] ;
    }
};    
 

// { Driver Code Starts.
int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	Solution ob;
    	cout <<ob.countFriendsPairings(n); 
    	cout<<endl;
    }
} 
  // } Driver Code Ends