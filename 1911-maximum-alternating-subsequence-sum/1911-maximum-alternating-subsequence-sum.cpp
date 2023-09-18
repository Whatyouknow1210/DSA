class Solution {
    // DP with memoization (make dp same as of return type)
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
public:
    long long maxAlternatingSum(vector<int>& nums) {
        memset(dp,-1,sizeof dp);
        return max(f(nums.size()-1,true,nums),f(nums.size()-1,false,nums));
        
        
    }
};