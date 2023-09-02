class Solution {
    // int ans = INT_MAX;
    int n;
    int f(int i,string s,vector<string>&v,vector<int>&dp)
    {
        if(i==n)return 0;
        if(dp[i]!=INT_MAX)return dp[i];
        dp[i] = n-i;
        for(auto &it:v)
        {
            int newpos = s.find(it,i);
            if(newpos!=string::npos)
            {
                dp[i] = min(dp[i],newpos-i+f(newpos+it.length(),s,v,dp));
            }
        }
        return dp[i];
        // if(i>=n)return 0;
        // int ans = 1e9;
        // if(dp[i]!=-1)return dp[i];
        // for(int ind=i;ind<n;ind++)
        // {
        //     string n1 = s.substr(i,ind-i+1);
        //     if(st.find(n1)!=st.end())
        //     {
        //         ans = min(ans,f(ind+1,s,st,dp));
        //     }
        //     else ans = min(ans,ind-i+1+f(ind+1,s,st,dp));
        // }
        // return dp[i] = ans;
        // if(s.length()==1)
        // {
        //     return (st.find(s)!=st.end())?0:1;
        // }
        // int ans=0;
        // n = s.length();
        // if(st.find(s.substr(i))!=st.end())
        // {
        //     ans+=f(0,s.substr(i,n-i-1),st);
        // }
        // else
        // {
        //     ans=1+ans+f(0,s.substr(i+1,n-i-2),st);
        // }
        // return ans;
    }
public:
    int minExtraChar(string s, vector<string>& dict) {
        // unordered_set<string>st(dict.begin(),dict.end());
        // n = s.length();
        // vector<int>dp(n+1,-1);
        // return f(0,s,st,dp);
        n = s.length();
        vector<int>dp(n+1,INT_MAX);
        return f(0,s,dict,dp);
    }
};