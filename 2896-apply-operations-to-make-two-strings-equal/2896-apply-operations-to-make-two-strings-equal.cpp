class Solution {
    int k;
    int f(int i,int j,vector<int>&cuts,vector<vector<int>>&dp)
    {
        if(i>=j)return dp[i][j]=0;
        int mini = INT_MAX;
        if(dp[i][j]!=-1)return dp[i][j];
        for(int ind = i+1;ind<=j;ind+=2)
        {
            int cost = min(k,abs(cuts[ind]-cuts[i]))+f(ind+1,j,cuts,dp)+f(i+1,ind-1,cuts,dp);
            mini = min(mini,cost);
        }
        return dp[i][j] = mini;
    }
public:
    int minOperations(string s1, string s2, int x) {
        k=x;
        int n = s1.length();
        int cnt=0;
        vector<int>nums;
        for(int i=0;i<n;++i)
        {
            cnt+=(s1[i]!=s2[i]);
            if(s1[i]!=s2[i])
            nums.push_back(i);
        }
        if(s1==s2)return 0;
        if(cnt%2)return -1;
        int size = nums.size();
        vector<vector<int>>dp(size+3,vector<int>(size+3,-1));
        return f(0,size-1,nums,dp);
    }
};