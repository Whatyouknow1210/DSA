class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& arr) {
        // For each bit store the next right index where you can get that bit (set bit) and update the next right index for every set bit as we encounter that bit in a number and for each index answer will be the the furthest index to right, for bits that have been found set in the elements to right of the current element.
        int n = arr.size();
        vector<int>bits(31,0); // set as 0 for all bits
        vector<int>ans(n);
        for(int i=n-1;i>=0;--i)
        {
            int maxRbit = 1;
            for(int bit = 0;bit < 31; ++bit)
            {
                if((arr[i]>>bit)&1)
                {
                    bits[bit] = i;
                }
                maxRbit = max(maxRbit,bits[bit] - i + 1);
            }
            ans[i] = maxRbit;
        }
        return ans;
    }
};
/* 
[0]
[1,0,2,1,3]
[1,2]
[4,2,4,25,2,12,42,1,135,312,521]
[1,3,4,2,5,2,1000000000,121]
*/