//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int MinimumEffort(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        int dir[] = {-1,0,1,0,-1};
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

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n,m; cin>>n>>m;
        vector<vector<int>> heights;
       
        for(int i=0; i<n; ++i){
            vector<int> temp;
            for(int j=0; j<m; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            heights.push_back(temp);
        }
       
        Solution obj;
        cout<<obj.MinimumEffort(heights)<<"\n";
    }
    return 0;
}
// } Driver Code Ends