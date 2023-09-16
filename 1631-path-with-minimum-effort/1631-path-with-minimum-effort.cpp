class Solution {
    // DFS with Binary Search
    int n,m;
    int dir[5] = {-1,0,1,0,-1};
    int f(int k,int r,int c,vector<vector<int>>& heights,vector<vector<int>>& vis)
    {
        if(r==n-1 && c==m-1)
            return true;
        vis[r][c] = 1;
        int ans = false;
        for(int i=0;i<4;++i)
        {
            int nr = r + dir[i];
            int nc = c + dir[i+1];
            if(nr>=0 && nr<n && nc>=0 && nc<m && vis[nr][nc]==0 && abs(heights[nr][nc]-heights[r][c])<=k && vis[nr][nc]==0)
            {
                ans|=f(k,nr,nc,heights,vis);
                if(ans)return true;
            }
        }
        // vis[r][c] = 0;
        return ans;
    }
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        n = heights.size();
        m = heights[0].size();
        // int res = 0;
        int low = 0,high = 1e6+10;
        while(low<=high)
        {
            vector<vector<int>>vis(n,vector<int>(m,0));
            int mid = (low+high)/2;
            if(f(mid,0,0,heights,vis))
            {
                high = mid-1;
            }
            else low = mid+1;
        }
        return low;
    }
};
/*
 BFS
 // // Intitialised distance array
        // vector<vector<int>>dis(n,vector<int>(m,1e6+10));
        // // Intitialised a priority queue
        // priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        // dis[0][0] = 0;
        // pq.push({0,{0,0}});
        // while(!pq.empty())
        // {
        //     auto curr = pq.top();
        //     pq.pop();
        //     int dist = curr.first;
        //     int x = curr.second.first;
        //     int y = curr.second.second;
        //     // If we reach the destination then that must be the minimum effort path so we return the dis
        //     if(x==n-1 && y==m-1)return dist;
        //     for(int i=0;i<4;i++)
        //     {
        //         int nx = x + dir[i];
        //         int ny = y + dir[i+1];
        //         if(nx>=0 && nx<n && ny>=0 && ny<m && (dis[nx][ny] > max(dist,abs(heights[x][y]-heights[nx][ny]))))
        //         {
        //             dis[nx][ny] = max(dist,abs(heights[x][y]-heights[nx][ny]));
        //             pq.push({dis[nx][ny],{nx,ny}});
        //         }
        //     }
        // }
        // // If not reachable
        // return -1;
*/