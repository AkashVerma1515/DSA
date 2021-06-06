// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int maxLen(int A[], int n);

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++)
            cin >> A[i];
        cout << maxLen(A, N) << endl;
    }
}
// } Driver Code Ends


/*You are required to complete this function*/

int maxLen(int a[], int n)
{
    int sum = 0 , maxi = 0;
    unordered_map<int,int> m;
    for(int i=0;i<n;i++)
    {
        sum = sum + a[i];
        if(sum==0)
        {
            maxi = i+1;
        }
        else if(m.find(sum) != m.end())
        {
            maxi = max(maxi,i-m[sum]);
        }
        else
        {
            m[sum] = i;
        }
    }
    return maxi;
}
