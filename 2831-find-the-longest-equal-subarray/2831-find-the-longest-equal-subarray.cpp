class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<n;++i)
        {
            mp[nums[i]].push_back(i);
        }
        // Question 4 from Weekly-Contest 359 
        // Sliding Window + Map
        int maxi =1;
        for(auto &[ke,v]:mp)
        {
            int i=1,j=1;
            int ind = v.size();
            int sum = 0;
            while(i<ind)
            {
                sum+=(v[i]-v[i-1]-1);
                while(j<i && sum>k)
                {
                    sum-=(v[j]-v[j-1]-1);
                    ++j;
                }
                if(sum<=k)
                maxi = max(maxi,v[i]-v[j-1]+1-sum);
                ++i;
            }
        }
        return maxi;
    }
};