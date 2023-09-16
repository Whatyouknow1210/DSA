class Solution {
    // DFS
// vector<vector<int>>vis(n,vector<int>(m,0));
// int res = 0;
// return f(0,0,0,heights,vis);
// return res;
//     int f(int res,int r,int c,vector<vector<int>>& heights,vector<vector<int>>& vis)
//     {
//         if(r==n-1 && c==m-1)
//             return res;
//         vis[r][c] = 1;
//         int ans = 1e4+10;
//         for(int i=0;i<4;++i)
//         {
//             int nr = r + dir[i];
//             int nc = c + dir[i+1];
//             if(nr>=0 && nr<n && nc>=0 && nc<m && vis[nr][nc]==0)
//             {
//                 int newres = 0;
//                 if(res<abs(heights[r][c]-heights[nr][nc]))
//                 {
                    
//                 }
//                 ans = min(ans,f(newres,nr,nc,heights,vis));
//             }
//         }
//         vis[r][c] = 0;
//         return ans;
//     }
    int n,m;
    int dir[5] = {-1,0,1,0,-1};
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        n = heights.size();
        m = heights[0].size();
        // Intitialised distance array
        vector<vector<int>>dis(n,vector<int>(m,1e6+10));
        // Intitialised a priority queue
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        dis[0][0] = 0;
        pq.push({0,{0,0}});
        while(!pq.empty())
        {
            auto curr = pq.top();
            pq.pop();
            int dist = curr.first;
            int x = curr.second.first;
            int y = curr.second.second;
            // If we reach the destination then that must be the minimum effort path so we return the dis
            if(x==n-1 && y==m-1)return dist;
            for(int i=0;i<4;i++)
            {
                int nx = x + dir[i];
                int ny = y + dir[i+1];
                if(nx>=0 && nx<n && ny>=0 && ny<m && (dis[nx][ny] > max(dist,abs(heights[x][y]-heights[nx][ny]))))
                {
                    dis[nx][ny] = max(dist,abs(heights[x][y]-heights[nx][ny]));
                    pq.push({dis[nx][ny],{nx,ny}});
                }
            }
        }
        // If not reachable
        return -1;
    }
};