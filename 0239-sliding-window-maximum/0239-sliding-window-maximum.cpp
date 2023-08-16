class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>ans;
        int n = nums.size();
        deque<int>dq;
        int sz = 0; // maintain a variable to get current size of the deque
        for(int i=0;i<n;i++)
        {
            while(sz && (nums[i]>=nums[dq.back()])) // pop the elements less than current element from deque
            {
                --sz;
                dq.pop_back();
            }
            ++sz;
            dq.push_back(i); // push the current element
            if(sz && dq.front()<=i-k) // If the element added doesn't fit in the window the pop it out
            {
                dq.pop_front();
                --sz;
            }
            if(i>=k-1)
            ans.push_back(nums[dq.front()]); // Finally the result will be at the front of the deque
        }
        return ans;
    }
};