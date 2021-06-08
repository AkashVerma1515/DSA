// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution{
    public:
    int longestKSubstr(string s, int k) {
        unordered_map<char,int> m;
        int i=0,j=0,n=s.length(), maxi = -1;
        while(j<n)
        {
            m[s[j]]++;
            if(m.size() < k)
            {
                j++;
            }
            else if(m.size() == k)
            {
                maxi = max(maxi,j-i+1);
                j++;
            }
            else
            {
                while(m.size() > k)
                {
                    m[s[i]]--;
                    if(m[s[i]] == 0)
                    {
                        m.erase(s[i]);
                    }
                    i++;
                }
                j++;
            }
        }
        return maxi;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}
  // } Driver Code Ends