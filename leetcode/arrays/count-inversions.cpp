// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
long long inv_count = 0;

void merge(long long arr[], long long l, long m, long long r)
{
    // long long inv_count = 0;
    long long n1 = m-l+1;
    long long n2 = r-m;
    long long L[n1],R[n2];
    for(int i=0;i<n1;i++)
    {
        L[i] = arr[i+l];
    }
    for(int i=0;i<n2;i++)
    {
        R[i] = arr[m+1+i];
    }
    long long i=0,j=0,k=l;
    while(i<n1 && j<n2)
    {
        if(L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
            inv_count += n1-i;
        }
        k++;
    }
    while(i<n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while(j<n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
    // return inv_count;
}

void mergeSort(long long arr[], long long l, long long r)
{
    // long long inv_count = 0;
    if(l<r)
    {
        long long m = l + (r-l)/2;
        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);
        merge(arr,l,m,r);
    }
    // return inv_count;
}

long long int inversionCount(long long arr[], long long N)
{
    // long long temp[N];
    mergeSort(arr,0,N-1);
    return inv_count;
}


};

// { Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}
  // } Driver Code Ends