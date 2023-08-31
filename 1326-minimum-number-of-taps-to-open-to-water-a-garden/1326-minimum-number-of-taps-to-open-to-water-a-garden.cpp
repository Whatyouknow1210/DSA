class Solution {
public:
// Brute Force 
/*
        T.C: O(n*m)
        S.C: O(n)
        vector<int>dp(n+1,1e9);
        dp[0] = 0;
        for(int i=0;i<=n;++i)
        {
            int lb = max(0,i-ranges[i]);
            int rb = min(n,i+ranges[i]);
            for(int j=lb;j<=rb;++j)
            {
                dp[rb] = min(dp[rb],dp[j]+1);
            }
        }
        return dp[n]==1e9?-1:dp[n];
*/
    int minTaps(int n, vector<int>& ranges) {
        vector<int>max_so_far(n+1);
        for(int i=0;i<=n;++i)
        {
            int st = max(0,i-ranges[i]);
            int end = min(n,i+ranges[i]);
            max_so_far[st] = max(max_so_far[st],end);
        }
        int taps = 0;
        int curr = 0;
        int next = 0;
        for(int i=0;i<=n;++i)
        {
            if(i>next)return -1;
            if(i>curr)
            {
                ++taps;
                curr = next;
            }
            next = max(next,max_so_far[i]);
        }
        return taps;
    }
};