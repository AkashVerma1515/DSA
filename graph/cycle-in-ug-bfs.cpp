// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution 
{
    public:
    //Function to detect cycle in an undirected graph.
	bool isCycle(int V, vector<int>adj[])
	{
	    vector<int> vis(V,0);
	    queue<pair<int,int>> q;
	    int prev = -1;
	    for(int i=0;i<V;i++)
	    {
	        if(!vis[i])
	        {
	            q.push({i,prev});
	            while(!q.empty())
	            {
	                pair<int,int> p = q.front();
	                q.pop();
	                vis[p.first] = 1;
	                for(int i=0;i<adj[p.first].size();i++)
	                {
	                    if(!vis[adj[p.first][i]])
	                    {
	                       // prev = adj[p.first];
	                        q.push({adj[p.first][i] , p.first});
	                    }
	                    else if(adj[p.first][i] != p.second)
	                    {
	                        return true;
	                    }
	                }
	            }
	        }
	    }
	    return false;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isCycle(V, adj);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}  // } Driver Code Ends