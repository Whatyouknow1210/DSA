class Solution {
    // string lcs(string text1, string text2) {
    //     reverse(text2.begin(),text2.end());
    //     int n = text1.size();
    //     int m = text2.size();
    //     vector<vector<int>>dp(m+1,vector<int>(m+1,0));
    //     // for(int j=0;j<=m;j++)
    //     // prev[j]=0;
    //     for(int i=1;i<=n;i++)
    //     {
    //         for(int j=1;j<=m;j++)
    //         {
    //             if(text1[i-1]==text2[j-1]) dp[i][j] = 1;
    //             // else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
    //         }
    //         // prev = curr;
    //     }
    //     // cout<<dp[m][n];
    //     // return prev[m];
    //     string ans="";
    //     for(int i=1;i<=n;i++)
    //     {
    //         for(int j=1;j<=m;j++)
    //         {
    //             if(dp[i][j]){ans+=text1[i-1];break;}
    //         }
    //     }
    //     return ans;
    // }
    // string longestCommonSubstr (string &s)
    // {
    //     int n = s.length();
    //     string ans = "";
    //     // int res = 0;
    //     vector<vector<int>>dp(n,vector<int>(n,0));
    //     int l = 0,r = 0;
    //     for(int i=0;i<n-1;i++)
    //     {
    //        dp[i][i] = 1;
    //        if(s[i]==s[i+1])
    //        {
    //            dp[i][i+1] = 1;
    //            l=i;
    //            r=i+1;
    //        }
    //     }
    //     dp[n-1][n-1] = 1;
    //     for(int diff = 2;diff<n;++diff)
    //     {
    //         for(int i=0;i<n-diff;i++)
    //         {
    //             int j = i+diff;
    //             if(s[i]==s[j] && dp[i+1][j-1])
    //             {
    //                 dp[i][j] = 1;
    //                 l=i;r=j;
    //             }
    //         }
    //     }
    //     // cout<<res<<endl;
    //     return s.substr(l,r-l+1);
    // }
public:
    string longestPalindrome(string s) {
        // string b = s;
        // reverse(begin(s),end(s));
        // return longestCommonSubstr(s);
        int n = s.length();
        string ans = "";
        int maxLen = 0;
        for(int i=0;i<n;i++)
        {
            int l = i,r=i;
            while(l>=0 && r<n && s[l]==s[r])
            {
                --l;++r;
            }
            if(r-l-1>maxLen)
                {
                    maxLen = r-l-1;
                    ans = s.substr(l+1,r-l-1);
                }
            l = i,r=i+1;
            while(l>=0 && r<n && s[l]==s[r])
            {
                --l;++r;
            }
            if(r-l-1>maxLen)
                {
                    maxLen = r-l-1;
                    ans = s.substr(l+1,maxLen);
                }
        }
        return ans;
    }
};