class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        // unordered_map<int,int>groups;
        vector<vector<int>>ans;
        unordered_map<int,vector<int>>mp;
        int n = groupSizes.size();
        for(int i=0;i<n;++i)
        {
            auto &y = mp[groupSizes[i]];
            y.push_back(i);
            if(y.size()==groupSizes[i])
            {
                ans.push_back(y);
                y.clear();
            }
        }
        return ans;
    }
};
/* 
    3 3 3 3 3 3 1 
    0 1 2 3 4 5 6 
    2 1 3 3 3 2 
    0 1 3 4 5 6 
*/