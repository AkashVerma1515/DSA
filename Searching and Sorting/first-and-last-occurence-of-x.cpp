// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
vector<int> find(int a[], int n , int x );

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}


// } Driver Code Ends


int first(int arr[], int n, int x)
{
	int low = 0, high = n-1, res = -1;
	while(low <= high)
	{
		int mid = low + (high-low)/2;
		if(arr[mid] > x)
		{
			high = mid-1;
		}
		else if(arr[mid] < x)
		{
			low = mid+1;
		}
		else
		{
			res = mid;
			high = mid-1;
		}
	}
	return res;
}
int second(int arr[], int n, int x)
{
	int low = 0, high = n-1, res = -1;
	while(low <= high)
	{
		int mid = low + (high-low)/2;
		if(arr[mid] > x)
		{
			high = mid-1;
		}
		else if(arr[mid] < x)
		{
			low = mid+1;
		}
		else
		{
			res = mid;
			low = mid+1;
		}
	}
	return res;
}

vector<int> find(int arr[], int n , int x )
{
	vector<int> v;
    int f = first(arr,n,x);
    int s = second(arr,n,x);
    v.push_back(f);
    v.push_back(s);
    return v;
}