class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        int l = 1;
        int n = s.size();
        int score = 0;
        for(int i=0;i<n;++i)
        {
            if(score+widths[s[i]-'a']==100)
            {
                ++l;
                score = 0;
            }
            else 
            {
                if(score+widths[s[i]-'a']>100)
                {
                    ++l;
                    score = widths[s[i]-'a'];
                }
                else score+=widths[s[i]-'a'];
            }
        }
        if(score==0)
        {
            return {l-1,100};
        }
        return {l,score};
    }
};