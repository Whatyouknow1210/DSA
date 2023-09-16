class Solution {
public:
    int countPairs(vector<vector<int>>& coordinates, int k) {
        map<pair<int,int>,int>mp;
        int ans = 0;
        // Look at size of k
        for(auto &it:coordinates)
        {
            for(int k1=0;k1<=k;++k1)
            {
                int p = (it[0]^k1);
                int q = (it[1]^(k-k1));
                ans+=mp[{p,q}];
                // ans+=mp[{(k-q),k1}];
            }
            ++mp[{it[0],it[1]}];
        }
        return ans;
    }
};