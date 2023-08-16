class Solution {
public:
    int halveArray(vector<int>& nums) {
        priority_queue<double>pq;
        long double sum = 0;
        for(auto &i:nums)
        {
            pq.push(i);
            sum+=i;
        }
        long double sum2 = sum;
        int ops = 0;
        while(2ll*sum2>sum)
        {
            double top = pq.top();
            pq.pop();
            sum2-=top/2;
            pq.push(top/2);
            ++ops;
        }
        return ops;
    }
};