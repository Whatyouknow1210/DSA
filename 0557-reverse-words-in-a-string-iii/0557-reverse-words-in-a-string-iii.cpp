class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        int j = 0;
        bool f = false;
        int i = 0;
        for(i=0;i<n;++i)
        {
            if(!f && s[i]!=32)
            {
                f = true;
            }
            if(s[i]==32)
            {
                reverse(s.begin()+j,s.begin()+i);
                j = i+1;
                f = false;
            }
        }
        reverse(s.begin()+j,s.begin()+i);
        return s;
    }
};