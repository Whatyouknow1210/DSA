class Solution {
    bool f(int ind,vector<int>&bucket,vector<int>&matches,int tar)
    {
        if(ind<0)
        {
            for(auto it:bucket)if(it!=tar)return false;
            return true;
        }
        for(int i=0;i<bucket.size();++i)
        {
            if(bucket[i]+matches[ind]>tar)continue;
            int j = i;
            while(--j>=0)
            {
                if(bucket[i]==bucket[j])break;
            }
            if(j!=-1)continue;
            bucket[i] += matches[ind];
            if(f(ind-1,bucket,matches,tar))return true;
            bucket[i] -= matches[ind];
        }
        return false;
    }
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int tot = accumulate(begin(nums),end(nums),0);
        sort(begin(nums),end(nums));
        vector<int>buck(k,0);
        if(tot%k)return false;
        tot/=k;
        return f(nums.size()-1,buck,nums,tot);
    }
};