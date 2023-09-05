class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        
                // One Pass
        int res = 0, i = 0, count = 0, n = nums.size();
        for (int j = 0; j < n; j++) {
            if (nums[j] & 1)
                --k, count = 0;
            while (k == 0)
                k += nums[i++] & 1, ++count;
            res += count;
        }
        return res;
        

        /* Two Pointers */
        // Number of subarrays with atmost k odd - Number of subarrays with atmost k-1 odd == Number of Subarrays with k odd
        // int i=0,j=0;
        // int n = nums.size();
        // int cnt = 0;
        // int ans = 0;
        // while(i<n)
        // {
        //     cnt+=(nums[i]&1);
        //     while(cnt>k)
        //     {
        //         cnt-=(nums[j]&1);
        //         ++j;
        //     }
        //     ans+=(i-j+1);
        //     ++i;
        // }
        // i=0,j=0,cnt=0;
        // int ans1 = 0;
        // --k;
        // while(i<n)
        // {
        //     cnt+=(nums[i]&1);
        //     while(cnt>k)
        //     {
        //         cnt-=(nums[j]&1);
        //         ++j;
        //     }
        //     ans1+=(i-j+1);
        //     ++i;
        // }
        // return ans-ans1;


        /* Using Map */
        // int n = nums.size();
        // int i=0;
        // int ans = 0;
        // int cnt = 0;
        // unordered_map<int,int>mp;
        // mp[0] = 1;
        // for(int i=0;i<n;++i)
        // {
        //     cnt+=(nums[i]%2);
        //     // cnt%=k;
        //     ans+=mp[cnt-k];
        //     ++mp[cnt];
        // }
        // return ans;
    }
};