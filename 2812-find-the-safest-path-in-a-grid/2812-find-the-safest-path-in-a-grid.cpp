class Solution {
    int dir[5] = {-1,0,1,0,-1};
    int n;
    // Gives TLE
    // void flood(int a,int b,vector<vector<int>>&grid,vector<vector<int>>&vis)
    // {
    //     for(int i=0;i<4;i++)
    //     {
    //         int nrow = a + dir[i];
    //         int ncol = b+dir[i+1];
    //         if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==0 && (vis[nrow][ncol]>1+vis[a][b] || vis[nrow][ncol]==0))
    //         {
    //             vis[nrow][ncol] = 1+vis[a][b];
    //             flood(nrow,ncol,grid,vis);
    //         }
    //     }
    // }
    bool dfs(int dis,int row,int col,vector<vector<int>>&vis,vector<vector<int>>&vis2)
    {
        if(row==n-1 && col==n-1)return vis[row][col]>dis;
        vis2[row][col] = 1;
        bool ans = false;
        for(int i=0;i<4;i++)
        {
            int nrow = row + dir[i];
            int ncol = col + dir[i+1];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<n && !vis2[nrow][ncol]  && vis[nrow][ncol]>dis)
            {
                ans |= dfs(dis,nrow,ncol,vis,vis2);
                if(ans)return ans;
            }
        }
        // vis2[row][col] = 0;
        return ans;
    }
    // Can't ind this way so do BS
    // int dfs(int row,int col,vector<vector<int>>&vis,vector<vector<int>>&vis2)
    // {
    //     if(row<0 || col<0 || col>=m || row>=n)return 0;
    //     if(vis2[row][col])return 0;
    //     if(row==0 && col==0)return vis[row][col];
    //     int ans = 0;
    //     for(int i=0;i<4;i++)
    //     {
    //         int nrow = row + dir[i];
    //         int ncol = row+dir[i+1];
    //         if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis2[nrow][ncol])
    //         {
    //             vis2[nrow][ncol] = 1;
    //             ans = max(ans,max(vis[nrow][ncol],dfs(nrow,col,vis,vis2)));
    //             vis2[nrow][ncol] = 0;
    //         }
    //     }
    //     return ans;
    // }
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        n = grid.size();
        if(grid[0][0] || grid[n-1][n-1])return 0;
        vector<vector<int>>vis(n,vector<int>(n,0));
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j])
                {
                    q.push({i,j});
                    // flood(i,j,grid,vis);
                }
            }
        }
        while(!q.empty())
        {
            auto curr = q.front();
            q.pop();
            for(int i=0;i<4;++i)
            {
                int r = curr.first + dir[i];
                int c = curr.second + dir[i+1];
                if(min(r,c)>=0 && max(r,c)<n && grid[r][c]==0 && (vis[r][c]>1+vis[curr.first][curr.second] || vis[r][c]==0))
                {
                    vis[r][c] = 1+vis[curr.first][curr.second];
                    q.push({r,c});
                }
            }
        }
        // for(auto i:vis)
        // {
        //     for(auto j:i)
        //     cout<<j<<" ";
        //     cout<<endl;
        // }
        int low = 0,high = n*n;
        int res = 0;
        while(low<high)
        {
            int mid = low+(high-low)/2;
            vector<vector<int>>vis2(n,vector<int>(n,0));
            if(vis[0][0]>mid && dfs(mid,0,0,vis,vis2))
            {
                // res = mid;
                low = mid+1;
            }
            else high = mid;
        }
        return low;
        
        // priority_queue<pair<int,pair<int,int>>>q;
        // q.push({1e9,{0,0}});
        // if(grid[0][0]==1)return 0;
        // while(!q.empty())
        // {
        //     int x = q.top().first;
        //     int y = q.top().second.first;
        //     int z =  q.top().second.second;
        //     vis2[y][z] = 1;
        //     if(y==n-1 && z==m-1)return x;
        //     q.pop();
        //     for(int i=0;i<4;i++)
        //     {
        //         int nrow = y + dir[i];
        //         int ncol = z+dir[i+1];
        //         if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis2[nrow][ncol]==0)
        //         {
        //             int mini = min(vis[nrow][ncol],x);
        //             q.push({x,{nrow,ncol}});
        //         }
        //     }
        // }
        // return dfs(n-1,m-1,vis,vis2);
        return -1;
    }
};