class Solution {
    // Recursion : 
    // Could've used a DP array of double size to remove the negative indices effect when doing top down
    // int dp[101][101];
       /*
        memset(dp,-1,sizeof dp);
        if(p==0)
        {
            return (m==0 && n==0);
        }
        return f(0,0,s1,s2,s3);
        */
    // bool f(int i,int j,string &s1,string &s2,string &s3)
    // {
    //     // cout<<i<<j<<k<<endl;
    //     int k = i+j;
    //     if(k==s3.length())
    //     {
    //         return true;
    //     }
    //     if(dp[i][j]!=-1)return dp[i][j];
    //     // if(i<0 || j<0)return false;
    //     bool ans = false;
    //     if(s1[i]==s3[k])
    //     {
    //         ans|=f(i+1,j,s1,s2,s3);
    //     }
    //     if(s2[j]==s3[k])
    //     {
    //         ans|=f(i,j+1,s1,s2,s3);
    //     }
    //     return dp[i][j] = ans;
    // }
    /*
        2D DP:
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        dp[0][0] =true;
        for(int i=1;i<=n;i++)
        {
           dp[i][0] = (dp[i-1][0] && (s1[i-1]==s3[i-1]));
        }
        for(int j=1;j<=m;j++)
        {
            dp[0][j] = (dp[0][j-1] && (s2[j-1]==s3[j-1]));
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                dp[i][j] = ((dp[i-1][j] && s1[i-1]==s3[i+j-1])||(dp[i][j-1] && s2[j-1]==s3[i+j-1]));
            }
        }
        return dp[n][m];
    */
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n,m,p;
        n = s1.length();
        m = s2.length();
        p = s3.length();
        if(n+m!=p)return false;
        if(n<m)
        {
            swap(n,m);
            swap(s1,s2);
        }
        vector<bool>dp(m+1,false);
        dp[0] = true;
        for(int i=1;i<=m;i++)
        {
            dp[i] = (dp[i-1] && s2[i-1]==s3[i-1]);
        }
        for(int i=1;i<=n;i++)
        {
            dp[0] = (dp[0] && s1[i-1]==s3[i-1]);
            for(int j=1;j<=m;j++)
            {
                dp[j] = (dp[j] && s1[i-1]==s3[i+j-1])||(dp[j-1] && s2[j-1]==s3[i+j-1]);
            }
        }
        return dp[m];
    }
};