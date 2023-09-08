class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        for(int i=0;i<numRows;++i)
        {
            vector<int>res(i+1,1);
            ans.push_back(res);
            ans[i][i] = 1;
            ans[0][0] = 1;
            for(int j=1;j<i;++j)
            {
                ans[i][j] = ans[i-1][j]+ans[i-1][j-1];
            }
        }
        return ans;
    }
};