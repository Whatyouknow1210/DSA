class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int sum = 0;
        int n = cardPoints.size();
        int j = n-k;
        while(j<n)
        {
            sum+=cardPoints[j++];
        }
        int ans = 0;
        ans = max(ans,sum);
        for(int i=0;i<k;++i)
        {
            sum+=cardPoints[i];
            sum-=cardPoints[n-k+i];
            ans = max(ans,sum);
        }
        return ans;
    }
};
// Using Sliding Window