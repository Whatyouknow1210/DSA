class Solution {
    // int ways(vector<int>&nums,int target,vector<int>&dp)
    // {
    //     if(target<0)return 0 ;
    //     if(target==0)return 1;
    //     if(dp[target]!=-1)return dp[target];
    //     int ans = 0;
    //     for(int &num:nums)
    //     {
    //         ans+=ways(nums,target-num,dp);
    //     }
    //     return dp[target] = ans;
    // }
public:
    int combinationSum4(vector<int>& nums, int target) {
        // sort(begin(nums),end(nums));
        // vector<int>dp(target+1,-1);
        // return ways(nums,target,dp);
        vector<unsigned int>dp(target+1,0);
        dp[0] = 1;
        for(int i=1;i<=target;++i)
        {
            for(int &num:nums)
            {
                dp[i] += (i>=num)?dp[i-num]:0;
            }
        }
        return dp[target];
    }
};