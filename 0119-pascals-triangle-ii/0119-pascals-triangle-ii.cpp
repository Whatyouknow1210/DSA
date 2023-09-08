class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int>ans(rowIndex+1,1);
        long long res = rowIndex;
        for(int i = 1;i<=(rowIndex+1)/2;++i)
        {
            ans[i] = res;
            ans[rowIndex-i] = res;
            res*=(rowIndex-i);
            res/=(i+1);
        }
        return ans;
    }
};