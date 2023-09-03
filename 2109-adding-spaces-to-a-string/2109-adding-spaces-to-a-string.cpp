class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int j = 0;
        int n = spaces.size();
        int space = 0;
        int m = s.length();
        string ans = "";
        for(int i=0;i<m;++i)
        {
            while(j<n && i==spaces[j])
            {
                ++space;
                ++j;
                ans+=' ';
            }
            ans+=s[i];
        }
        return ans;
    }
};
// 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 
// i   c o d e i n p y t h  o  n