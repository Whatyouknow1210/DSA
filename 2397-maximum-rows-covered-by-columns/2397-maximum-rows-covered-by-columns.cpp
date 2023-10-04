class Solution {
    // int n,m;
    // int maxi;
    // int f(int i,int p,vector<vector<int>> &mp)
    // {
    //     // if(maxi==n)return maxi;
    //     if(i==0)
    //     {
    //         int cnt = 0;
    //         for(int r=0;r<n;++r)
    //         {
    //             bool fl = true;
    //             for(int c=0;c<m;++c)
    //             {
    //                 if(mp[r][c])
    //                 {
    //                     if(((p>>c)&1)==false)fl=false;
    //                 }
    //             }
    //             cnt += fl;
    //         }
    //         maxi = max(maxi,cnt);
    //         return maxi;
    //     }
    //     if(dp[i][p]!=-1)return dp[i][p];
    //     int ans = -1e9;
    //     ans = max(ans,f(i-1,p,mp));
    //     for(int j=0;j<m;++j)
    //     {
    //         ans = max(ans,f(i-1,p|(1<<j),mp));
    //     }
    //     return dp[i][p] = ans;
    // }
public:
// Function to get next mask !
    // int next_popcount(int n)
    // {
    //     int c = (n & -n);
    //     int r = n + c;
    //     return (((r ^ n) >> 2 ) / c) | r;
    // }
    int maximumRows(vector<vector<int>>& matrix, int numSelect) {
        // maxi = 0;
        // memset(dp,-1,sizeof dp);
        // n = matrix.size();
        // m = matrix[0].size();
        // for(int mask = (1<<numSelect)-1;mask < (1<<m); mask = next_popcount(mask))
        // {
        //     int row = 0;
        //     for(int i=0,j=0;i<n;++i)
        //     {
        //         for(j=0;j<m;++j)
        //         {
        //             if(matrix[i][j] && (mask & (1 << j)) == 0)
        //             break;
        //         }
        //         row += (j==m);
        //     }
        //     maxi = max(maxi,row);
        // }
        // // return f(numSelect,0,matrix);
        // return maxi;
        vector<int> row_mask;
        int all_0 = 0, n = matrix.size(), m = matrix[0].size();
        for (int i = 0, cur = 0; i < n; i+=1, cur = 0) {
            for (int j = 0; j < m; j+=1)
                if (matrix[i][j]) cur |= 1 << j;
            if (cur) row_mask.emplace_back(cur);
            else all_0 += 1;
        }
        int col_used = 0, ans = 0;
        function<void(int)> dfs = [&] (int i) {
            if (__builtin_popcount(col_used) == numSelect) {
                ans = max(ans, accumulate(row_mask.begin(), row_mask.end(), 0, [&] (int s, int& x) {return s + ((x & col_used) == x);}));
                return;
            }
            else if (__builtin_popcount(col_used) + m - i < numSelect) return;
            dfs(i+1);
            col_used |= 1 << i;
            dfs(i+1);
            col_used ^= 1 << i;
        };
        dfs(0);
        return ans + all_0;
    }
};
 // Another Clean Approach
/* 
vector<int> row_mask;
        int all_0 = 0, n = matrix.size(), m = matrix[0].size();
        for (int i = 0, cur = 0; i < n; i+=1, cur = 0) {
            for (int j = 0; j < m; j+=1)
                if (matrix[i][j]) cur |= 1 << j;
            if (cur) row_mask.emplace_back(cur);
            else all_0 += 1;
        }
        int col_used = 0, ans = 0;
        function<void(int)> dfs = [&] (int i) {
            if (__builtin_popcount(col_used) == numSelect) {
                ans = max(ans, accumulate(row_mask.begin(), row_mask.end(), 0, [&] (int s, int& x) {return s + ((x & col_used) == x);}));
                return;
            }
            else if (__builtin_popcount(col_used) + m - i < numSelect) return;
            dfs(i+1);
            col_used |= 1 << i;
            dfs(i+1);
            col_used ^= 1 << i;
        };
        dfs(0);
        return ans + all_0;
        */