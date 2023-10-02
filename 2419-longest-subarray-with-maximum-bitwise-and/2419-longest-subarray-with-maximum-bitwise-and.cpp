class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int cnt = 0;
        int val = 0;
        int ans = 0;
        for(auto it :nums)
        {
            if(it>val)
            {
                cnt = 1;
                val = it;
                ans = 1;
            }
            else if(it==val)
            {
                ++cnt;
                ans = max(ans,cnt);
            }
            else cnt = 0;
        }
        return ans;
    }
};