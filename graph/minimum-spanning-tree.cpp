// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
// 	struct node {
//     int u;
//     int v;
//     int wt; 
//     node(int first, int second, int weight) {
//         u = first;
//         v = second;
//         wt = weight;
//     }
// };
	
	static bool comp(vector<int> &a, vector<int> &b) {
        return a[2] < b[2] ; 
    }
    
    int findPar(int u, vector<int> &parent) {
        if(u == parent[u]) return u; 
        return parent[u] = findPar(parent[u], parent); 
    }

    void merge(vector<int> &parent, int j, int i)
    {
        parent[findPar(j,parent)] = findPar(i,parent);
    }
    
    
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<vector<int>> edges;
        for(int i=0;i<V;i++)
        {
            for(auto it : adj[i])
            {
                edges.push_back({i, it[0], it[1]});
            }
        }
        sort(edges.begin(),edges.end(),comp);
        int cnt = 0;
        vector<int> parent(V);
    	for(int i =0 ;i<V ;i++) 
	    {
	        parent[i] = i; 
	    }
	   // vector<int> rank(N, 0);
    	int cost = 0;
    // 	vector<pair<int,int>> mst; 
    	for(auto it : edges) {
    	    if(cnt==V-1)
    	    {
    	        return cost;
    	    }
	        if(findPar(it[0], parent) != findPar(it[1], parent)) {
	            cost += it[2];
	            ++cnt;
	           // mst.push_back({it.u, it.v}); 
	           // unionn(parent, it[1], it[0]); 
	           merge(parent,it[1],it[0]);
	        }      
        }
        return cost;
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends