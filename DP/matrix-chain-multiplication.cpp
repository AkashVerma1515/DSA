// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int dp[1001][1001];
    
    int matrix(int a[], int i, int j)
    {
        if(i>=j)        // only one element or no element.
        {
            return 0;
        }
        if(dp[i][j] != -1)
        {
            return dp[i][j];
        }
        int temp, mini = INT_MAX;
        for(int k=i ; k<=j-1 ; k++)        // there must be two function call thats why k <= j-1.
        {
            temp = matrix(a,i,k) + matrix(a,k+1,j) + (a[i-1]*a[k]*a[j]);
            mini = min(temp,mini);
        }
        dp[i][j] = mini;
        return mini;
    }
    
    int matrixMultiplication(int N, int arr[])
    {
        for(int i=0;i<1001;i++)
        {
            for(int j=0;j<1001;j++)
            {
                dp[i][j] = -1;
            }
        }
        int ans = matrix(arr,1,N-1);
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}  // } Driver Code Ends