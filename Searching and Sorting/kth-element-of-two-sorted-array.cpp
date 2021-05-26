// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    int kthElement(int a[], int b[], int m, int n, int k)
    {
        int i = 0 , j = 0 , k1 = 0;
        while(i<m && j<n)
        {
            if(a[i] < b[j])
            {
                k1++;
                if(k1==k)
                {
                    return a[i];
                }
                i++;
            }
            else
            {
                k1++;
                if(k1==k)
                {
                    return b[j];
                }
                j++;
            }
        }
        while(i<m)
        {
            k1++;
            if(k1==k)
            {
                return a[i];
            }
            i++;
        }
        while(j<n)
        {
            k1++;
            if(k1==k)
            {
                return b[j];
            }
            j++;
        }
        
    }
};

// { Driver Code Starts.
 
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n,m,k;
		cin>>n>>m>>k;
		int arr1[n],arr2[m];
		for(int i=0;i<n;i++)
			cin>>arr1[i];
		for(int i=0;i<m;i++)
			cin>>arr2[i];
		
		Solution ob;
        cout << ob.kthElement(arr1, arr2, n, m, k)<<endl;
	}
    return 0;
}  // } Driver Code Ends