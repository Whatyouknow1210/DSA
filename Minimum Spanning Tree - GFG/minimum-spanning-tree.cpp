//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        // edge weight, src
        int vis[V] = {};
        pq.push({0,0});
        int minWeight = 0;
        while(!pq.empty())
        {
            int wt = pq.top().first;
            int src = pq.top().second;
            pq.pop();
            if(vis[src])continue;
            // if(src!=-1)
            // {
                vis[src] = 1;
                minWeight += wt;
            // }
            for(auto& next:adj[src])
            {
                if(vis[next[0]]==0)
                pq.push({next[1],next[0]});
            }
        }
        return minWeight;
    }
};

//{ Driver Code Starts.


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