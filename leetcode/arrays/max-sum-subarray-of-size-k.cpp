// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{   
public:

	// SLIDING WINDOW
	// T.C : O(N)
	// S.C : O(1)
	
    int maximumSumSubarray(int k, vector<int> &a , int N){
        int i=0,j=0;
        int maxi = INT_MIN;
        int sum = 0;
        while(j<N)
        {
            sum = sum + a[j];
            if(j-i+1 < k)
            {
                j++;
            }
            else if(j-i+1 == k)
            {
                maxi = max(sum,maxi);
                sum = sum - a[i];
                i++;
                j++;
            }
        }
        return maxi;
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N,K;
        cin >> N >> K;;
        vector<int>Arr;
        for(int i=0;i<N;++i){
            int x;
            cin>>x;
            Arr.push_back(x);
        }
        Solution ob;
        cout << ob.maximumSumSubarray(K,Arr,N) << endl;
    }
    return 0; 
}   // } Driver Code Ends