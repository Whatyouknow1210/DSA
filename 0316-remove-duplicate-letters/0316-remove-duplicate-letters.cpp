class Solution {
public:
    string removeDuplicateLetters(string s) {
        map<char,int>mp,flag;
        int n = s.length();
        stack<char>st;
        string ans = "";
        for(auto it:s)++mp[it];
        for(int i=0;i<n;++i)
        {
            // cout<<s[i]<<" "<<mp[s[i]]<<" "<<flag[s[i]]<<endl;
                if(flag[s[i]])
                {
                    --mp[s[i]];
                    continue;
                }
                while(st.size() && st.top() > s[i] && mp[st.top()]>=1)
                {
                    // mp[st.top()];
                    flag[st.top()] = 0;
                    st.pop();
                }
                    st.push(s[i]);
                    flag[s[i]] = 1;
                    --mp[s[i]];
        }
        while(st.size())
        {
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
// acddcab
// aabcdacdb
// b c a
// a c d c a
// dcababcd
// a b c d

// cbacdcbc
// acdb