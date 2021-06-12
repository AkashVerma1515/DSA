// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    vector<string> ans;
    void dfs(vector<vector<int>> &m, int n, int x, int y, string s, map<pair<int, int>, bool> &vis)
    {

        if (vis[{x, y}] || m[x][y] == 0)
            return;
        
        if(x<0 || y<0 || x>=n || y>=n)
        {
            return;
        }
        
        if ((x == n - 1) && (y == n - 1))
        {
            ans.push_back(s);
            return;
        }

        vis[{x, y}] = true;

        if (((x - 1) >= 0) && (m[x - 1][y] == 1))
        {
            dfs(m, n, x - 1, y, s + "U", vis);
        }

        if (((x + 1) < n) && (m[x + 1][y] == 1))
        {
            dfs(m, n, x + 1, y, s + "D", vis);
        }

        if (((y - 1) >= 0) && (m[x][y - 1] == 1))
        {
            dfs(m, n, x, y - 1, s + "L", vis);
        }

        if (((y + 1) < n) && (m[x][y + 1] == 1))
        {
            dfs(m, n, x, y + 1, s + "R", vis);
        }

        vis[{x, y}] = false;
        return;
    }

    vector<string> findPath(vector<vector<int>> &m, int n)
    {
        map<pair<int, int>, bool> vis;
        ans.clear();

        if (m[0][0] == 0)
            return ans;
            
        if (m[n-1][n-1] == 0)
            return ans;
            
        dfs(m, n, 0, 0, "", vis);

        sort(ans.begin(), ans.end());
        return ans;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends