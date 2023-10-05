class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cnt1=0,cnt2=0,num1=-1,num2=-1;
        int n = nums.size();
        int lim = n/3;
        vector<int>ans;
        for(int i=0;i<n;++i)
        {
           if(cnt1==0 && nums[i]!=num2)
           {
               num1 = nums[i];
               ++cnt1;
           }
           else if(nums[i]==num1)
           {
               ++cnt1;
           }
           else if(cnt2==0 && nums[i]!=num1)
           {
               cnt2 = 1;
               num2 = nums[i];
           }
            else if(nums[i]==num2)
            {
                ++cnt2;
            }
           else 
            {
                --cnt1,--cnt2; // Reduce both as for each element having > n/3 freq it must have 2 elements which it oe=vertakes per frequency (understand!) also verification is necesarry !
            }
        }
        // cout<<num1<<" "<<num2<<" "<<cnt1<<" "<<cnt2<<endl;
        cnt1 = 0,cnt2=0;
        for(int num :nums)
        {
            if(num1==num)++cnt1;
            else if(num2==num)++cnt2;
        }
        if(cnt1>n/3)
        {
            ans.push_back(num1);
        }
        if(cnt2>n/3)
        {
            ans.push_back(num2);
        }
        return ans;
    }
};