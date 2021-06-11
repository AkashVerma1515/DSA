// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        queue<pair<int,int>> q;
        int n = image.size();
        int m = image[0].size();
        int fixed = image[sr][sc];
        int vis[n][m];
        memset(vis,0,sizeof(vis));
        q.push({sr,sc});
        while(!q.empty())
        {
            auto cur = q.front();
            int i = cur.first;
            int j = cur.second;
            q.pop();
            if(vis[i][j])
            {
                continue;
            }
            vis[i][j] = 1;
            if((i>=0 && i<n) && (j+1>=0 && j+1<m))
            {
                if(image[i][j+1] == fixed)
                {
                    q.push({i,j+1});
                    image[i][j+1] = newColor;
                }
            }
            if((i>=0 && i<n) && (j-1>=0 && j-1<m))
            {
                if(image[i][j-1] == fixed)
                {
                    q.push({i,j-1});
                    image[i][j-1] = newColor;
                }
                
            }
            if((i-1>=0 && i-1<n) && (j>=0 && j<m))
            {
                if(image[i-1][j] == fixed)
                {
                    q.push({i-1,j});
                    image[i-1][j] = newColor;
                }
                
            }
            if((i+1>=0 && i+1<n) && (j>=0 && j<m))
            {
                if(image[i+1][j] == fixed)
                {
                    q.push({i+1,j});
                    image[i+1][j] = newColor;
                }
                
            }
            image[sr][sc] = newColor;
        }
        return image;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}  // } Driver Code Ends