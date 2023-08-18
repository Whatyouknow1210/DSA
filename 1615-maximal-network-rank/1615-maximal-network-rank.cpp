class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<vector<int>>adj(n);
        for(auto &it:roads)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==j)continue;
                bool f = false;
                int cnt = 0;
                for(auto &it:adj[i])
                {
                    if(it==j)f=true;
                    ++cnt;
                }
                for(auto &it:adj[j])
                {
                    if(it==i)f=true;
                   ++cnt;
                }
                // cout<<i<<" "<<j<<" "<<s.size()<<endl;
                ans = max(ans,cnt-f);
            }
        }
        return ans;
    }
};