class Solution {
    int cnt = 0;
    long long dfs(int par,int node,vector<vector<int>>&adj,vector<int>&values,int k)
    {
        long long curr = values[node];
        for(auto it:adj[node])
        {
            if(it!=par)
            curr += dfs(node,it,adj,values,k);
        }
        if(curr%k==0)++cnt;
        return curr;
    }
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>>adj(n);
        cnt = 0;
        for(auto it:edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        dfs(-1,0,adj,values,k);
        return cnt;
    }
};