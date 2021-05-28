// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
bool isSubsetSum(int a[], int sum, int n)
 {
 	bool c[n+1][sum+1];
//  	for(int i=0;i<n+1;i++)
//  	{
//  	    c[i][0] = true;
//  	}
//  	for(int j=1;j<sum+1;j++)
//  	{
//  	    c[0][j] = false;
//  	}
 	for(int i=0;i<n+1;i++)
 	{
 		for(int j=0;j<sum+1;j++)
 		{
 			if(j==0)
 			{
 				c[i][j] = true;
 			}
 			else if(i==0)
 			{
 				c[i][j] = false;
 			}
 			else if(a[i-1] <= j)
 			{
 				c[i][j] = c[i-1][j-a[i-1]] || c[i-1][j];
 			}
 			else
 			{
 				c[i][j] = c[i-1][j];
 			}
 		}
 	}
 	return c[n][sum];
 }
    int equalPartition(int N, int arr[])
    {
        int sum = 0;
        for(int i=0;i<N;i++)
        {
            sum = sum + arr[i];
        }
        if(sum&1)
        {
            return 0;
        }
        if(isSubsetSum(arr,sum/2,N))
        {
           return 1;
        }
        else
        {
            return 0;
        }
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
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}  // } Driver Code Ends