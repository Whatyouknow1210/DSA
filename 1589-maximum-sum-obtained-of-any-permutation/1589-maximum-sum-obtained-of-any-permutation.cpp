class Solution {
    const int mod =1e9+7;
public:
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
        int n = nums.size();
        vector<long long>pref(n+1,0);
        for(auto &i:requests)
        {
            ++pref[i[0]];
            --pref[i[1]+1];
        }
        for(int i=1;i<=n;i++)
        {
            pref[i]+=pref[i-1];
        }
        // cout<<endl;
        // for(auto _:pref)
        // {
        //     cout<<_<<" ";
        // }
        sort(begin(nums),end(nums));
        sort(begin(pref),begin(pref)+n);
        long long ans = 0;
        for(int i=0;i<n;i++)
        {
            ans=(ans + 1ll*pref[i]*nums[i])%mod;
        }
        return ans%mod;
    }
};
// 0 1 2 3 4 
        