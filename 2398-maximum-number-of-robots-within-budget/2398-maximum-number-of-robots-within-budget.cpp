class Solution {
public:
    int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {
        int n =runningCosts.size();
        vector<long long>prefsum(n);
        prefsum[0] = runningCosts[0];
        for(int i=1;i<n;i++)
        {
            prefsum[i]+=prefsum[i-1]+runningCosts[i];
        }
        int i=0,j=0;
        int ans = 0;
        multiset<int>ms;
        while(i<n)
        {
            ms.insert(chargeTimes[i]);
            long long p = (prefsum[i]-(j==0?0:prefsum[j-1]));
            int maxi = *ms.rbegin();
            while(j<i && budget<(maxi+(i-j+1)*p))
            { 
                ms.erase(ms.find(chargeTimes[j]));
                ++j;
                 p = (prefsum[i]-(j==0?0:prefsum[j-1]));
                maxi = *ms.rbegin();
            }
            // cout<<maxi<<" "<<p<<" "<<(i-j+1)<<endl;
            if(budget>=chargeTimes[i]+runningCosts[i])
            ans = max(ans,i-j+1);
            ++i;
        }
        return ans;
    }
};