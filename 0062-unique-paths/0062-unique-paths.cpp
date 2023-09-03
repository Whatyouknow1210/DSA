class Solution {
public:
    int uniquePaths(int m, int n) {
        /* DP */
        // vector<int>prev(m,0);
        // for(int i=0;i<n;i++)
        // {
        //     vector<int>curr(m,0);
        //     for(int j=0;j<m;j++)
        //     {
        //         if(i==0&&j==0)
        //         curr[j]=1;
        //         else
        //         {
        //             int up=0;
        //         int left=0;
        //         if(i>0) up = prev[j];
        //         if(j>0) left = curr[j-1];
        //         curr[j] = up+left;
        //         }
        //     }
        //     prev = curr;
        // }
        // return prev[m-1];
        /* Combinatorics */
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);cout.tie(NULL);
        int N = n+m-2;
        int r = m-1;
        double res =1;
        for(int i=1;i<=r;i++)
        {
            res = res*(N-r+i)/i;
        }
        return (int)res;
    }
};