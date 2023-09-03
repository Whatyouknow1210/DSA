class Solution {
    int dp[3002][3002];
    const int mod = 1e9+7;
    int countWays(int currPos,int endPos,int k)
    {
        if(k==0)
        {
            return currPos==endPos;
        }
        if(dp[currPos+1001][k]!=-1)return dp[currPos+1001][k];
        long long ans = 0;
        ans = (ans + countWays(currPos+1,endPos,k-1)%mod+countWays(currPos-1,endPos,k-1)%mod)%mod;
        return dp[currPos+1001][k] = ans;
    }
public:
    int numberOfWays(int startPos, int endPos, int k) {
        memset(dp,-1,sizeof dp);
        return countWays(startPos,endPos,k);
    }
};