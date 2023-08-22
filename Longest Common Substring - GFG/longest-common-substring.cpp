//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    // int dp[1001][1001][2];
    public:
    int ans = 0;
    // int lcSs(string &s1,string &s2,int i,int j,bool found)
    // {
    //     if(i<0 || j<0)return 0;
    //     if(dp[i][j][found]!=-1)return dp[i][j][found];
    //     int maxi = 0;
    //     if(s1[i]==s2[j])
    //     {
    //         if(found)
    //         {
    //             maxi = 1+lcSs(s1,s2,i-1,j-1,1);
    //         }
    //         else
    //         {
    //             maxi = 1+lcSs(s1,s2,i-1,j-1,0);
    //         }
    //         // found = true;
    //     }
    //     else
    //     {
    //         maxi = max(maxi,max(lcSs(s1,s2,i-1,j,0),lcSs(s1,s2,i,j-1,0)));
    //         // found = false;
    //     }
    //     return dp[i][j][found] = maxi;
    // } 
    int longestCommonSubstr (string S1, string S2, int n, int m)
    {
    //     memset(dp,-1,sizeof dp);
    //   lcSs(S1,S2,n-1,m-1,0);
        int ans = 0;
        vector<int>prev(m+1,0);
        for(int i=1;i<=n;i++)
        {
            vector<int>curr(m+1,0);
            for(int j=1;j<=m;j++)
            {
                if(S1[i-1]==S2[j-1])
                {
                    curr[j] = 1 + prev[j-1];
                    ans = max(ans,curr[j]);
                }
                else curr[j] = 0;
            }
            prev = curr;
        }
        return ans;
    }
};
// 
     //     i j 
     //    1 + 





//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr (s1, s2, n, m) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends