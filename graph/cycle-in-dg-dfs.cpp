// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution
{
    public:
	//Function to detect cycle in a directed graph.
	
	bool check(int i, vector<int> adj[], vector<bool> &vis, vector<bool> &dfsVis)
	{
	    vis[i] = 1;
	    dfsVis[i] = 1;
	    for(auto it:adj[i])
	    {
	        if(!vis[it])
	        {
	            if(check(it,adj,vis,dfsVis))
	            {
	                return true;
	            }
	        }
	        else if(vis[it] == 1 && dfsVis[it] == 1)
	        {
	            return true;
	        }
	    }
	    dfsVis[i] = 0;  // if no cycle
	    return false;
	}
	
	bool isCyclic(int V, vector<int> adj[]) 
	{
	   	vector<bool> vis(V);
	   	vector<bool> dfsVis(V);
	   	for(int i=0;i<V;i++)
	   	{
	   	    vis[i] = 0;
	   	    dfsVis[i] = 0; 
	   	}
	   	for(int i=0;i<V;i++)
	   	{
	   	    if(!vis[i])
	   	    {
	   	        if(check(i,adj,vis,dfsVis))
	   	        {
	   	            return true;
	   	        }
	   	    }
	   	}
	   	return false;
	}
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends