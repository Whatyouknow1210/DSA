class Solution {
    // TLE at 11th Test Case 
    // int dp[1ll<<15][16];
    int sum = 0;
    bool dfs(int i,vector<int>&buckets,vector<int>&match)
    {
        if(i<0)
        {
            // sort(buckets.begin(),buckets.end()); // causes change in elements asthe vector is passed by reference !!
            // return *min_element(buckets.begin(),buckets.end())==*max_element(buckets.begin(),buckets.end());
            return buckets[0]==buckets[1] && buckets[1]==buckets[2] && buckets[2]==buckets[3];
        }
        // bool f = false;
        for(int ind=0;ind<4;ind++)
        {
            if(sum<buckets[ind]+match[i])continue;
             
            int j = ind;
            while(--j>=0)
            {
                if(buckets[ind]==buckets[j])break;
            }
            if(j!=-1)continue;
            buckets[ind]+=match[i];
            if(dfs(i-1,buckets,match))return  true;
            buckets[ind]-=match[i];
        }
        return  false;
        // return f;
    }
public:
    bool makesquare(vector<int>& matchsticks) {
        int n = matchsticks.size();
        vector<int>buckets(4,0);
        sum = accumulate(matchsticks.begin(),matchsticks.end(),0);
        if(sum%4)return false;
        sum/=4;
        sort(matchsticks.begin(),matchsticks.end());
        // memset(dp,-1,sizeof dp);
        return dfs(n-1,buckets,matchsticks);
    }
};