class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        int mod = 1e9+7;
        vector<long long>dis(n,LLONG_MAX),ways(n,0);
        vector<vector<pair<int,long long>>>adj(n);
        for(auto it:roads)
        {
            // cout<<it[0]<<" "<<it[1]<<" "<<it[2]<<endl;
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        ways[0] = 1;
        dis[0] = 0;
        // Using Dikjstra's ALgorithm to get shortest path and thus updating ways !
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>pq;
        pq.push({0,0});
        while(!pq.empty())
        {
            long long curr = pq.top().first;
            int node = pq.top().second;
            // cout<<curr<<" "<<node<<endl;
            pq.pop();
            for(auto it : adj[node])
            {
                // cout<<curr<<" "<<node<<" "<<it.first<<" "<<it.second<<" "<<dis[it.first]<<endl;
                int des = it.first;
                if(curr + it.second < dis[des])
                {
                    // cout<<curr<<" "<<node<<" "<<it.first<<" "<<dis[des]<<endl;
                    dis[des] = curr + it.second;
                    ways[des] = (ways[node])%mod;// the new path will have the ways equal to ways of path till here
                    pq.push({dis[des],des});
                }
                else if(curr + it.second == dis[des])
                {
                    ways[des] = (ways[des] + ways[node])%mod;
                }
            }
        }
        return ways[n-1];
    }
};