class Solution {
    int dp[501][501];
    int f(int i,int j,vector<int>&nums1,vector<int>&nums2)
    {
        if(i<0 || j<0)return -1e9;
        if(dp[i][j]!=-1)return dp[i][j];
        int ans = nums1[i]*nums2[j]+max(0,f(i-1,j-1,nums1,nums2));
        ans = max(ans,max(f(i-1,j,nums1,nums2),f(i,j-1,nums1,nums2)));
        return dp[i][j] = ans;
    }
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        memset(dp,-1,sizeof dp);
        return f(n-1,m-1,nums1,nums2);
    }
};