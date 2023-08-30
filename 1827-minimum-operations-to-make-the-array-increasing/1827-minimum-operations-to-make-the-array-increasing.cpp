class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i=1;i<n;++i)
        {
            ans += max(0,1-nums[i]+nums[i-1]);
            nums[i] += max(0,1-nums[i]+nums[i-1]);
        }
        return ans;
    }
};