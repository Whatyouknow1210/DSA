class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n = s.length();
        map<char,pair<bool,char>>mp1,mp2;
        for(int i=0;i<n;++i)
        {
            if(mp1[s[i]].first==true)
            {
                if(t[i]!=mp1[s[i]].second)return false;
            }
            else 
            {
                mp1[s[i]] = {true, t[i]};
            }
            if(mp2[t[i]].first==true)
            {
                if(s[i]!=mp2[t[i]].second)return false;
            }
            else 
            {
                mp2[t[i]] = {true, s[i]};
            }
        }
        return true;
    }
};