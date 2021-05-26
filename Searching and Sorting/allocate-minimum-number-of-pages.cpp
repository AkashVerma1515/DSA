// { Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    
    bool isPossible(int a[], int n, int m, int mid)
    {
        int student = 1;
        int sum = 0;
        for(int i=0;i<n;i++)
        {
            sum = sum + a[i];
            if(sum > mid)
            {
                student++;
                sum = a[i];
            }
            if(student > m)
            {
                return false;
            }
        }
        return true;
    }
    
    int findPages(int a[], int n, int m) 
    {
        if(n<m)
        {
            return -1;
        }
        int sum = 0;
        int maxi = INT_MIN;
        for(int i=0;i<n;i++)
        {
            sum = sum + a[i];
            maxi = max(maxi,a[i]);
        }
        int start = maxi;
        int end = sum;
        int res = INT_MAX;
        while(start <= end)
        {
            int mid = start + (end-start)/2;
            if(isPossible(a,n,m,mid))
            {
                res = min(res,mid);
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        return res;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}
  // } Driver Code Ends