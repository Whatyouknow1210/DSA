//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    int dir[5] = {-1,0,1,0,-1};
    void dfs(int i,int j,int n,int m,vector<vector<char>>&mat,vector<vector<char>>&ans,vector<vector<char>>&vis)
    {
        ans[i][j] = 'O';
        vis[i][j] = '1';
        for(int ind=0;ind<4;++ind)
        {
            int nrow = i + dir[ind];
            int ncol = j + dir[ind+1];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol] == '0' && ans[nrow][ncol]!='O' && mat[nrow][ncol]=='O')
            {
                dfs(nrow,ncol,n,m,mat,ans,vis);
            }
        }
    }
public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        vector<vector<char>>ans(n,vector<char>(m,'X')),vis(n,vector<char>(m,'0'));
        for(int i=0;i<n;++i)
        {
            if(mat[i][0]=='O' && vis[i][0]=='0')
            {
                dfs(i,0,n,m,mat,ans,vis);
            }
            if(mat[i][m-1]=='O' && vis[i][m-1]=='0')
            {
                dfs(i,m-1,n,m,mat,ans,vis);
            }
        }
        for(int j=0;j<m;++j)
        {
            if(mat[0][j]=='O' && vis[0][j]=='0')
            {
                dfs(0,j,n,m,mat,ans,vis);
            }
            if(mat[n-1][j]=='O' && vis[n-1][j]=='0')
            {
                dfs(n-1,j,n,m,mat,ans,vis);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends