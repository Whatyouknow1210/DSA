class Solution {
public:
    int bestClosingTime(string customers) {
        int y = 0,n = 0;
        int len = 0;
        for(auto &it:customers)
        {
            y+=(it=='Y');
            ++len;
        }
        int ans = y;
        int ind = 0;
        for(int i=0;i<len;++i)
        {
            n+=(customers[i]=='N');y-=(customers[i]=='Y');
            int pen = y+n;
            if(ans>pen)
            {
                ind = i+1;
                ans = pen;
            }
        }
        return ind;
    }
};
// from right calc the one which has least number of y to its right and least number of n to its left
// YYNYN --> 3 2 1 2 1 2