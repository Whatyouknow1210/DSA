class Solution {
public:
    string breakPalindrome(string s) {
        int l = 0,r = s.length()-1;
        if(l==r)return "";
        while(l<r)
        {
            if(s[l]!='a')
            {
                s[l] = 'a';
                return s;
            }
            ++l;
            --r;
        }
        s.back()+=1;
        return s;
    }
};