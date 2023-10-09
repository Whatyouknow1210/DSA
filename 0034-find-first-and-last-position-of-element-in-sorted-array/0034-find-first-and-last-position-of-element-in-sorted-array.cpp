class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int low =0,high=n-1;
        int p=-1,q=-1;
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            // cout<<low<<" "<<mid<<' '<<high<<endl;
            if(nums[mid]==target)
            {
                p = mid;
                high = mid-1;
            }
            else if(nums[mid]<target)
            {
                low = mid+1;
            }
            else high = mid-1;
        }
        low = 0,high=n-1;
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            if(nums[mid]==target)
            {
                q = mid;
                low = mid+1;
            }
            else if(nums[mid]<target)
            {
                low = mid+1;
            }
            else high = mid-1;
        }
        // cout<<p<<" "<<q<<endl;
        return {p,q};
    }
};