class Solution {
public:
    int countAsterisks(string s) {
        int bars=0,cnt=0;
        for(auto &it:s)
        {
            bars+=(it=='|');
            cnt+=(bars%2==0 && it=='*');
        }
        return cnt;
    }
};