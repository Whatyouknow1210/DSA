class Solution {
    int dp[101][10001];
    bool f(int i,int j,string &s,string &t)
    {
        if(i<0 || j<0)return false;
        if(s[i]==t[j]&&i==0)return true;
        if(dp[i][j]!=-1)return dp[i][j];
        bool ans = false;
        if(s[i]==t[j])
        {
            ans|=f(i-1,j-1,s,t);
        }
        ans|=f(i,j-1,s,t);
        return dp[i][j] = ans;
    }
public:
    bool isSubsequence(string s, string t) {
        memset(dp,-1,sizeof dp);
        if(s.length()==0)return 1;
        return f(s.length()-1,t.length()-1,s,t);
    }
};