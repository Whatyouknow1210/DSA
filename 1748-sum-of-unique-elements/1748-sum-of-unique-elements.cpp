class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        int cnt[101]={};
        int sum = 0;
        for(auto &it:nums)
        {
            if(cnt[it]==0)
            {
                sum+=it; 
            }
            else if(cnt[it]==1)
            {
                sum-=it;
}
            ++cnt[it];
        }
        return sum;
    }
};