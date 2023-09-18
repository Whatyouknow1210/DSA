class Solution {
    // DP with memoization (make dp same as of return type)
    /*
    memset(dp,-1,sizeof dp);
    return max(f(nums.size()-1,true,nums),f(nums.size()-1,false,nums));
    long long dp[100002][2]; 
    long long f(int i,bool fl,vector<int>&nums)
    {
        if(i<0)return 0;
        long long take = -1e18;
        if(dp[i][fl]!=-1)return dp[i][fl];
        if(fl)
        {
            take = max(take,nums[i]+f(i-1,!fl,nums));
        }
        else 
        {
            take = max(take,-nums[i]+f(i-1,!fl,nums));
        }
        return dp[i][fl] = max(take,f(i-1,fl,nums));
    }
        */
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        // Tabulation
        /*
        vector<vector<long long>>dp(n+1,vector<long long>(2,0));
        for(int i=1;i<=n;++i)
        {
            dp[i][1] = max(dp[i-1][1],dp[i-1][0]+nums[i-1]);
            dp[i][0] = max(dp[i][0],dp[i-1][1]-nums[i-1]);
            dp[i][0] = max(dp[i][0],dp[i-1][0]);
            dp[i][1] = max(dp[i][1],dp[i-1][1]);
        }
        return max(dp[n][0],dp[n][1]);
        */
        // long long newEven = max(evensum,oddsum+nums[i]);
        // long long newOdd = max(oddsum,evensum-nums[i]);
        // evensum = newEven;
        // oddsum = newOdd;
        long long evensum=0,oddsum=0;
        for(int i=0;i<n;++i)
        {
            evensum = max(evensum,oddsum+nums[i]);
            oddsum = max(oddsum,evensum-nums[i]);
        }
        return max(evensum,oddsum);
    }
};