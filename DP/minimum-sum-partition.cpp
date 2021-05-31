// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

	public:
	int findMin(int a[],int n,int sum)
	{
	    bool dp[n+1][sum+1];
	    for(int i=0;i<n+1;i++)
	    {
	        dp[i][0] = true;
	    }
	    for(int i=1;i<sum+1;i++)
	    {
	        dp[0][i] = false;
	    }
	    for(int i=1;i<n+1;i++)
	    {
	        for(int j=1;j<sum+1;j++)
	        {
	            if(a[i-1] <= j)
	            {
	                dp[i][j] = dp[i-1][j-a[i-1]] || dp[i-1][j];
	            }
	            else
	            {
	                dp[i][j] = dp[i-1][j];
	            }
	        }
	    }
	    int diff = INT_MAX;
	    for(int j = 0; j<=sum/2; j++)			// Range - 2*S1
	    {
	        if(dp[n][j] == true)
	        {
	            diff = min(diff,sum-2*j);
	        }
	    }
	    return diff;
	}
	
	int minDiffernce(int arr[], int n) 
	{ 
	    int sum = 0;
	    for(int i=0;i<n;i++)
	    {
	        sum += arr[i];
	    }
	    int ans = findMin(arr,n,sum);
	    return ans;
	} 
};


// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDiffernce(a, n) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends