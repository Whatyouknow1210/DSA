class Solution {
public:
    vector<int> partitionLabels(string s) {
        // if we include a character then we must include it's last occurence too so first we store the last occurence of every character in mp[] array
        // now for each new beginning we extend to the last occurence of character and we update the limit as the last occurence of each character countered in the way, thus greedily selecting maximum groups
        int mp[26] = {};
        int n = s.length();
        for(int i=0;i<n;++i)
        {
            mp[s[i]-'a'] = i;
        }
        vector<int>ans;
        for(int i=0;i<n;++i)
        {
            int x = mp[s[i]-'a'];
            int j = i+1;
            for(;j<=x;++j)
            {
                x = max(x,mp[s[j]-'a']);
            }
            ans.push_back(j-i);
            i=j-1;
        }
        return ans;
    }
};