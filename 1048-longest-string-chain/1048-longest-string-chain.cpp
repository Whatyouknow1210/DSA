class Solution {
    int dp[1001][1001];
    bool check(string &a,string &b)
    {
        int n = a.length();
        int m = b.length();
        if(n==m)  return false;
        if(n>m+1) return false;
         int i=0;
         int j=0;
        while(i<n)
            if(j<m && a[i]==b[j])
                i++,j++;
            else
                i++;
        if(i==n && j==m)
            return true;
        else
            return false;
    }
    int lsc(int i,int j,vector<string>&words)
    {
        if(i==words.size())
        {
            return 0;
        }
        if(dp[i][j+1]!=-1)return dp[i][j+1];
        int notake = 0 + lsc(i+1,j,words);
        if(j==-1 || check(words[i],words[j]))
        {
            notake = max(notake,1+lsc(i+1,i,words));
        }
        return dp[i][j+1] = notake;
    }
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),[](string &a,string&b){
            return a.size()<b.size();
        });
        int n = words.size();
        memset(dp,-1,sizeof dp);
        return lsc(0,-1,words);
    }
};