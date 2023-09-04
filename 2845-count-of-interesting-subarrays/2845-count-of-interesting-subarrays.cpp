class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        // Using Concept of Prefix Sum and Map we can get the answer
        // Decreasing from O(n2) --> O(n);
        int n = nums.size();
        long long ans = 0;
        vector<int>prefsum(n+1,0);
        for(int i=1;i<=n;++i)
        {
            prefsum[i]+=prefsum[i-1] + ((nums[i-1]%modulo==k));
            // cout<<prefsum[i]<<" "<<k-prefsum[i]%modulo;
        }
        unordered_map<int,int>mp;
        for(int i=0;i<=n;++i)
        {
            ans += mp[(prefsum[i]-k+modulo)%modulo];
            ++mp[(prefsum[i])%modulo];
            // for(int j=i+1;j<=n;++j)
            // {
            //     ans+=(((prefsum[j]-prefsum[i])%modulo)==k);
            // }
        }
        return ans;
    }

};