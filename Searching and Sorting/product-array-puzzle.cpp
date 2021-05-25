// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
        long long p = 1, z=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==0)
            {
                z++;
            }
        }
        for(int i=0;i<n;i++)
        {
            if(nums[i]!=0)
            {
                p = p*nums[i];
            }
        }
        // cout<<z<<endl;
        if(z==1)
        {
            for(int i=0;i<n;i++)
            {
                if(nums[i] == 0)
                {
                    nums[i] = p;
                }
                else
                {
                    nums[i] = 0;   
                }
            }
            return nums;
            // cout<<"jfs";
        }
        else if(z>1)
        {
            for(int i=0;i<n;i++)
            {
                nums[i] = 0;
            }
            return nums;
        }
        else if(z==0)
        {
            for(int i=0;i<n;i++)
            {
                nums[i] = p/nums[i];
            }
            return nums;
        }
        // return nums;
    }
};


// { Driver Code Starts.
int main()
 {
    int t;  // number of test cases
    cin>>t;
    while(t--)
    {
        int n;  // size of the array
        cin>>n;
        vector<long long int> arr(n),vec(n);
        
        for(int i=0;i<n;i++)    // input the array
        {
            cin>>arr[i];
        }
        Solution obj;
        vec = obj.productExceptSelf(arr,n);   // function call
        
        for(int i=0;i<n;i++)    // print the output
        {
            cout << vec[i] << " ";
        }
        cout<<endl;
    }
	return 0;
}  // } Driver Code Ends