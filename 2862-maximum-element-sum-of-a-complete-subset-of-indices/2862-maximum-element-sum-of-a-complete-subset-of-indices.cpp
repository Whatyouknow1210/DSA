class Solution {
    // Weekly Q.4) 
    // Finding the sequence as 1 4 9 16 
    // 2 8 18 32 ....
    // 3 12 27 
    // such numbers can form subset and these numbers are product of prime numbers such that the factor of multiplication is odd
    int f(int n)
    {
        int ans = 1;
        for(int i=2;i*i<=n;++i)
        {
            int cnt = 0;
            while(n%i==0)
            {
                ++cnt;
                n/=i;
            }
            if(cnt%2)
            {
                ans*=i;
            }
        }
        if(n>1)ans*=n;
        return ans;
    }
public:
    long long maximumSum(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size();
        unordered_map<int,long long>mp;
        for(int it=0;it<n;++it)
        {
            int x = f(it+1);
            mp[x]+=nums[it];
            ans = max(ans,mp[x]);
        }
        return ans;
    }
};