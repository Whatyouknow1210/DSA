class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int n = nums.size();
        sort(begin(nums),end(nums));
        int ans = 0;
        for(int i=1;i<n;++i)
        {
            if(nums[i]<=nums[i-1])
            {
                ans += 1+nums[i-1]-nums[i];
                nums[i] = nums[i-1]+1;
            }
        }
        return ans;
    }
};