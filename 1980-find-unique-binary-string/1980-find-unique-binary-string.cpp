class Solution {
    // Brute Force
    string p;
    bool rec(int i,int n,string res,unordered_set<string>&us)
    {
        if(i==n)
        {
            if(us.find(res)==us.end())
            {
                p = res;
                return true;
            }
            return false;
        }
        if(rec(i+1,n,res+'1',us))return true;
        if(rec(i+1,n,res+'0',us))return true;
        return false;
    }
public:
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_set<string>us(begin(nums),end(nums));
        string res = "";
        rec(0,nums[0].length(),res,us);
        return p;
    }
};