class Solution {
public:
    string reverseStr(string s, int k) {
        int n = s.length();
        int j = 0,i=0;
        for( i=0;i<n;++i)
        {
            if(i-j==2*k)
            {
                reverse(s.begin()+j,s.begin()+j+k);
                j = i;
            }
        }
        if(i-j>=k && i-j<=2*k)
        {
            reverse(s.begin()+j,s.begin()+j+k);
        }
        else 
        {
            reverse(s.begin()+j,s.end());
        }
        return s;
    }
};