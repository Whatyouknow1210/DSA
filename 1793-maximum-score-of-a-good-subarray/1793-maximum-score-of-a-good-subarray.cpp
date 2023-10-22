class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        // Can use next smaller to left and next smaller to right for each element and take the subarray as possible
        // and calculate answer ... Thinking reverse like in Codechef Que!
        // Using Stack and Next Smaller to Right Array while calculating next Smaller to left at Runtime
        stack<int>st;
        vector<int>nsr(n,n);
        // 2 3 1 2 4 
        for(int i=n-1;i>=0;--i)
        {
            while(st.size() && nums[st.top()]>=nums[i])
            {
                st.pop();
            }
            if(st.size())
            {
                nsr[i] = st.top();
            }
            st.push(i);
        }
        while(st.size())st.pop();
        int ans = 0;
        for(int i=0;i<n;++i)
        {
            while(st.size() && nums[st.top()]>=nums[i])
            {
                st.pop();
            }
            int nsl = st.size()?st.top():-1;
            st.push(i);
            if(nsr[i]-1>=k && k>=nsl+1)
            {
                // cout<<nums[i]<<" "<<nsl[i]<<" "<<nsr[i]<<endl; 
                ans = max(ans,nums[i]*(nsr[i]-nsl-1));
            }
        }
        return ans;
    }
};