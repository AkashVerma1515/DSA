// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
        vector<int> ans;
        ans.push_back(a[0]);
        for(int i=1;i<n;i++)
        {
            if(ans.back() < a[i])
            {
                ans.push_back(a[i]);
            }
            else                // Or we can use binary search.
            {
                int index = lower_bound(ans.begin(),ans.end(),a[i]) - ans.begin();   // to get the index of the element which is just greater than or equal to a[i] in given range   
                ans[index] = a[i];
            }
        }
        return ans.size();
        
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}
  // } Driver Code Ends