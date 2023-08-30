class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        int n = nums.size();
        int prev = nums[n-1];
        long long ans = 0;
        for(int i=n-2;i>=0;--i)
        {
            if(nums[i]>=prev)
            {
                int parts = (nums[i]+prev-1)/prev;
                ans+=parts-1;
                prev = nums[i]/parts;
            }
            else prev = nums[i];
        }
        return ans;
    }
};
// 821 881 275
// 821 220 220 220 221 275
// 205 205 205 206 220 220 220 221 275